#include <stdio.h>
#include <stdint.h>

uint32_t to_change(uint32_t a) {
        uint32_t a1 = (a & 0xff000000) >> 24;
        uint32_t a2 = (a & 0x00ff0000) >> 8;
        uint32_t a3 = (a & 0x0000ff00) << 8;
        uint32_t a4 = (a & 0x000000ff) << 24;
        return a1 | a2 | a3 | a4 ;
}

int main(int argc, char *argv[]){

	if(argc != 3)
		return 0;
	FILE *fp1 = fopen(argv[1],"r");
	FILE *fp2 = fopen(argv[2],"r");
	uint32_t a;
	uint32_t b;
	uint32_t res = 0;

	if(fp1 == NULL || fp2 == NULL){
		printf("파일 읽는 중 오류 발생");
		return 0;
	}
	fread(&a,4,1,fp1);
	fread(&b,4,1,fp2);
	a = to_change(a);
	b = to_change(b);
	res = a + b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,res,res);
	fclose(fp1);
	fclose(fp2);
	return 0;
}

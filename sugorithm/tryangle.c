#include<stdio.h>
#include<stdlib.h>
#include<string.h>


float calc_angle(int x1, int y1, int x2, int y2);
int main(void){
	int ax, ay, bx, by, cx, cy;
	int c1, c2, c3, c4, c5;
	float angle01, angle02, origin_angle;
	float temp_angle;
	int point;
	int result = 0;

	while(scanf("%d%c%d%c%d%c%d%c%d%c%d", &ax, &c1, &ay, &c2, &bx, &c3, &by, &c4, &cx, &c5, &cy) != EOF){
		point = 0;
		printf("%d %d %d %d %d %d\n", ax, ay, bx, by, cx, cy);

		angle01 = calc_angle(ax, ay, bx, by);
		angle02 = calc_angle(ax, ay, cx, cy);
		origin_angle = calc_angle(ax, ay, 0, 0);

		if(angle01 - angle02 < 0){
			angle01 += 360.0;
		}

		if(angle01 - angle02 < 180){
			if(origin_angle <= angle01 && origin_angle >= angle02){
				point += 1;
			}
		} else {
			if(origin_angle <= angle02 && origin_angle >= angle01){
				point += 1;
			}
		}

		printf("(1). 1 : %f, 2 : %f, ori : %f point : %d\n", angle01, angle02, origin_angle, point);

		angle01 = calc_angle(bx, by, ax, ay);
		angle02 = calc_angle(bx, by, cx, cy);
		origin_angle = calc_angle(bx, by, 0, 0);

		if(angle01 - angle02 < 0){
			angle01 += 360.0;
		}

		if(angle01 - angle02 < 180){
			if(origin_angle <= angle01 && origin_angle >= angle02){
				point += 1;
			}
		} else {
			if(origin_angle <= angle02 && origin_angle >= angle01){
				point += 1;
			}
		}
		printf("(2). 1 : %f, 2 : %f, ori : %f point : %d\n", angle01, angle02, origin_angle, point);

		angle01 = calc_angle(cx, cy, ax, ay);
		angle02 = calc_angle(cx, cy, bx, by);
		origin_angle = calc_angle(cx, cy, 0, 0);

		if(angle01 - angle02 < 0){
			angle01 += 360.0;
		}

		if(angle01 - angle02 < 180){
			if(origin_angle <= angle01 && origin_angle >= angle02){
				point += 1;
			}
		} else {
			if(origin_angle <= angle02 && origin_angle >= angle01){
				point += 1;
			}
		}
		printf("(3). 1 : %f, 2 : %f, ori : %f point : %d\n", angle01, angle02, origin_angle, point);

		if(point == 3){
			result += 1;
		}
		printf("point : %d\n", point);
	}

	printf("result : %d\n", result);



	




	return 0;
}

float calc_angle(int x1, int y1, int x2, int y2){
	int dx, dy, ax, ay;

	float t;

	dx = x2 - x1;
	ax = abs(dx);
	dy = y2 - y1;
	ay = abs(dy);

	t = (ax + ay == 0)?0:(float)dy/(ax+ay);

	if(dx < 0)
		t = 2 - t;
	else if(dy < 0)
		t = 4 + t;


	return t * 90.0;
}

//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//#include <string.h>
//#include <algorithm>
//using namespace std;
//int selected_menu = 0;
//bool antialiasing_on = 0;
//bool blending_on = 0;
//
//GLint point_x[150]; //마우스 클릭시 좌표 저장할 배열
//GLint point_y[150];
//int draw_mode = 0; //점,선,삼각형 모드를 정해준다.
//int draw_type[50] = { 0 }; //그리기 모드가 뭔지 정해준다.
//int num = 0;
//int num_p = 0;
//int a = 0;
//
//void init(void)
//{
//	/* 화면의 기본색을 black으로 설정 */
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	/* 화면 좌표 정보 설정 */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f); //얘때문에 좌측 하단이 0,0이 되는 것임
//}
//void draw_string(void* font, const char* str,
//	int x, int y)
//{
//	unsigned int i;
//	glRasterPos2i(x, y);
//	for (i = 0; i < strlen(str); i++) {
//		glutBitmapCharacter(font, str[i]);
//	}
//}
//void draw(void)
//{
//	/* 화면을 깨끗하게 지우기 */
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor4f(1.0, 1.0, 1.0, 0.7);
//	draw_string(GLUT_BITMAP_HELVETICA_18, "Hello It's Jin", 10, 10);
//
//	int i = 0;
//	int i_p = 0;
//
//	while (draw_type[i] != 0) {
//		if (draw_type[i] == 1 ) { // 점을 그리는 모드
//			glColor4f(1.0, 0.5, 0.5, 0.7);
//			glPointSize(6.0);
//			glBegin(GL_POINTS);
//			glVertex2i(point_x[i_p], point_y[i_p]);
//			glEnd();
//			i_p++;
//		}
//		else if (draw_type[i] == 2 ) { // 선을 그리는 모드
//			glLineWidth(7.0f); //선의 굵기를 7로 설정
//			/* 선의 색상 설정 */
//			glColor4f(0.5f, 1.0f, 0.5f, 0.7);
//			glBegin(GL_LINES); //얘 인자를 GL_LINES로 변경해줘야함
//			glVertex2i(point_x[i_p], point_y[i_p]);
//			glVertex2i(point_x[i_p + 1], point_y[i_p + 1]);
//			glEnd();
//			i_p += 2;
//		} 
//		else if (draw_type[i] == 3 ) { //삼각형을 그리는 모드
//			glColor4f(0.0f, 1.0f, 1.0f, 0.7);
//			glBegin(GL_TRIANGLES);
//			glVertex2i(point_x[i_p], point_y[i_p]);
//			glVertex2i(point_x[i_p + 1], point_y[i_p + 1]);
//			glVertex2i(point_x[i_p + 2], point_y[i_p + 2]);
//			glEnd();
//			i_p += 3;
//		}
//		i++;
//	}
//	glFlush();
//}
//void mouse(int button, int state, int x, int y) {
//	/* 인자들을 해석해서 원하는 기능을 구현 */
//	if (draw_mode != 0) {
//		if (button == GLUT_LEFT_BUTTON) {
//			if (state == GLUT_DOWN) {
//				printf("Mouse button is clicked! (%d, %d)\n", x, 500 - y);
//				draw_type[num] = draw_mode; //draw_type은 어느 형태였는지 저장해주는 배열
//				point_x[num_p] = x; //x좌표
//				point_y[num_p] = 500 - y; //y좌표
//				num_p++; //몇번째 점인지
//				a++;
//			}
//		}
//		if (a >= draw_mode) {
//			num++;
//			a = 0;
//			glutPostRedisplay();
//		}
//	}
//}
//void keyboard(unsigned char key, int x, int y)
//{
//	/* 인자들을 해석해서 원하는 기능을 구현 */
//	printf("\nYou pressed %c", key);
//	if (key == 'a')
//	{
//		char a_state[5] = {};
//		antialiasing_on = antialiasing_on ? false : true;
//		if (antialiasing_on) {
//			glEnable(GL_POINT_SMOOTH);
//			glEnable(GL_LINE_SMOOTH);
//			glEnable(GL_POLYGON_SMOOTH);
//			glutPostRedisplay();
//			strcpy_s(a_state, "ON");
//		}
//		else {
//			glDisable(GL_POINT_SMOOTH);
//			glDisable(GL_LINE_SMOOTH);
//			glDisable(GL_POLYGON_SMOOTH);
//			glutPostRedisplay();
//			strcpy_s(a_state, "OFF");
//		}
//		printf(", Antialiasing %s\n", a_state);
//	}
//	if (key == 'b')
//	{
//		char b_state[5] = {};
//		blending_on = blending_on ? false : true;
//		if (blending_on) {
//			glEnable(GL_BLEND);
//			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//			glutPostRedisplay();
//			strcpy_s(b_state, "ON");
//		}
//		else {
//			glDisable(GL_BLEND);
//			glutPostRedisplay();
//			strcpy_s(b_state, "OFF");
//		}
//		printf(", Blending %s\n", b_state);
//	}
//}
//
//void draw_menu_function(int option) {
//	printf("Drawmenu %d has been selected\n", option);
//	selected_menu = option;
//	draw_mode = option - 20;
//	printf("Draw Mode is %d\n", draw_mode);
//}
//void main_menu_function(int option)
//{
//	printf("Main menu %d has been selected\n", option);
//	if (option == 999) {
//		exit(0);
//	}
//	if (option == 11) {
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor4f(1.0, 1.0, 1.0, 0.7);
//	draw_string(GLUT_BITMAP_HELVETICA_18, "Hello It's Jin", 10, 10);
//	a = 0;
//	num = 0;
//	num_p = 0;
//	draw_mode = 0;
//	fill(draw_type, draw_type + 50, 0);
//	glFlush();
//	}
//}
//
//int main(int argc, char** argv)
//{
//	/* Window 초기화 */
//	glutInit(&argc, argv);
//	int drawmenu;
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init(); // -> 사용자 초기화 함수
//
//	drawmenu = glutCreateMenu(draw_menu_function);
//	glutAddMenuEntry("Point", 21);
//	glutAddMenuEntry("Line", 22);
//	glutAddMenuEntry("Triangle", 23);
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Clear!", 11);
//	glutAddSubMenu("Draw", drawmenu);
//
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback 함수 정의 */
//	glutMouseFunc(mouse);
//	glutDisplayFunc(draw);
//	glutKeyboardFunc(keyboard);
//
//	/* Looping 시작 */
//	glutMainLoop();
//	return 0;
//}
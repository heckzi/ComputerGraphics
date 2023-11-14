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
//GLint point_x[150]; //���콺 Ŭ���� ��ǥ ������ �迭
//GLint point_y[150];
//int draw_mode = 0; //��,��,�ﰢ�� ��带 �����ش�.
//int draw_type[50] = { 0 }; //�׸��� ��尡 ���� �����ش�.
//int num = 0;
//int num_p = 0;
//int a = 0;
//
//void init(void)
//{
//	/* ȭ���� �⺻���� black���� ���� */
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	/* ȭ�� ��ǥ ���� ���� */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f); //�궧���� ���� �ϴ��� 0,0�� �Ǵ� ����
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
//	/* ȭ���� �����ϰ� ����� */
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor4f(1.0, 1.0, 1.0, 0.7);
//	draw_string(GLUT_BITMAP_HELVETICA_18, "Hello It's Jin", 10, 10);
//
//	int i = 0;
//	int i_p = 0;
//
//	while (draw_type[i] != 0) {
//		if (draw_type[i] == 1 ) { // ���� �׸��� ���
//			glColor4f(1.0, 0.5, 0.5, 0.7);
//			glPointSize(6.0);
//			glBegin(GL_POINTS);
//			glVertex2i(point_x[i_p], point_y[i_p]);
//			glEnd();
//			i_p++;
//		}
//		else if (draw_type[i] == 2 ) { // ���� �׸��� ���
//			glLineWidth(7.0f); //���� ���⸦ 7�� ����
//			/* ���� ���� ���� */
//			glColor4f(0.5f, 1.0f, 0.5f, 0.7);
//			glBegin(GL_LINES); //�� ���ڸ� GL_LINES�� �����������
//			glVertex2i(point_x[i_p], point_y[i_p]);
//			glVertex2i(point_x[i_p + 1], point_y[i_p + 1]);
//			glEnd();
//			i_p += 2;
//		} 
//		else if (draw_type[i] == 3 ) { //�ﰢ���� �׸��� ���
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
//	/* ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ���� */
//	if (draw_mode != 0) {
//		if (button == GLUT_LEFT_BUTTON) {
//			if (state == GLUT_DOWN) {
//				printf("Mouse button is clicked! (%d, %d)\n", x, 500 - y);
//				draw_type[num] = draw_mode; //draw_type�� ��� ���¿����� �������ִ� �迭
//				point_x[num_p] = x; //x��ǥ
//				point_y[num_p] = 500 - y; //y��ǥ
//				num_p++; //���° ������
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
//	/* ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ���� */
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
//	/* Window �ʱ�ȭ */
//	glutInit(&argc, argv);
//	int drawmenu;
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init(); // -> ����� �ʱ�ȭ �Լ�
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
//	/* Callback �Լ� ���� */
//	glutMouseFunc(mouse);
//	glutDisplayFunc(draw);
//	glutKeyboardFunc(keyboard);
//
//	/* Looping ���� */
//	glutMainLoop();
//	return 0;
//}
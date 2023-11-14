//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//int selected_menu = 0;
//void init(void)
//{
//	/* 화면의 기본색으로 dark blue 설정 */
//	glClearColor(0.3f, 0.0f, 0.5f, 1.0f);
//	glMatrixMode(GL_PROJECTION);
//}
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float)height,
//		1, 500);
//	glMatrixMode(GL_MODELVIEW);
//}
//void draw_axis(void)
//{
//	glLineWidth(3); // 좌표축의 두께
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); // X축은 red
//	glVertex3f(0, 0, 0);
//	glVertex3f(4, 0, 0);
//	glColor3f(0, 1, 0); // Y축은 green
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 4, 0);
//	glColor3f(0, 0, 1); // Z축은 blue
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 4);
//	glEnd();
//	glLineWidth(1); // 두께 다시 환원
//}
//void draw(void) // 기존 함수 변경
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(30, 30, 30, 0, 0, 0, 0, 1, 0);
//	glColor3f(1, 1, 0);
//	glutWireTeapot(4);
//	draw_axis();
//	glFlush();
//	glutSwapBuffers(); // double buffering시
//}
//void main_menu_function(int option)
//{
//	printf("Main menu %d has been selected\n", option);
//	if (option == 999) {
//		exit(0);
//	}
//}
//int main(int argc, char** argv)
//{
//	/* Window 초기화 */
//	glutInit(&argc, argv);
//	int mainmenu;
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init(); // -> 사용자 초기화 함수
//
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback 함수 정의 */
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	/* Looping 시작 */
//	glutMainLoop();
//	return 0;
//}
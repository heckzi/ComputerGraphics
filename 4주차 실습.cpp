//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//int selected_menu = 0;
//void init(void)
//{
//	/* ȭ���� �⺻������ dark blue ���� */
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
//	glLineWidth(3); // ��ǥ���� �β�
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); // X���� red
//	glVertex3f(0, 0, 0);
//	glVertex3f(4, 0, 0);
//	glColor3f(0, 1, 0); // Y���� green
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 4, 0);
//	glColor3f(0, 0, 1); // Z���� blue
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 4);
//	glEnd();
//	glLineWidth(1); // �β� �ٽ� ȯ��
//}
//void draw(void) // ���� �Լ� ����
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(30, 30, 30, 0, 0, 0, 0, 1, 0);
//	glColor3f(1, 1, 0);
//	glutWireTeapot(4);
//	draw_axis();
//	glFlush();
//	glutSwapBuffers(); // double buffering��
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
//	/* Window �ʱ�ȭ */
//	glutInit(&argc, argv);
//	int mainmenu;
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init(); // -> ����� �ʱ�ȭ �Լ�
//
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback �Լ� ���� */
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	/* Looping ���� */
//	glutMainLoop();
//	return 0;
//}
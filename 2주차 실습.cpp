//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//
//double spin = 0;
//int selected_menu = 0;
//bool enable_spin = 0;
//void init(void)
//{
//	/* ȭ���� �⺻������ dark blue ���� */
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//	/* ȭ�� ��ǥ ���� ���� */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f); //�궧���� ���� �ϴ��� 0,0�� �Ǵ� ����
//}
//void draw_point(void)
//{
//	/* ���� ������ ���� ������ */
//	glColor3f(1.0f, 0.0f, 0.0f);
//	/* ���� ũ�� (�ʱⰪ�� 1.0)*/
//	glPointSize(15.0f);
//	glBegin(GL_POINTS); //gl Point�� ���� �׸��Ŷ�� ����
//	glVertex2i(30, 30); //���� ��ġ ���� , �Ʊ� init�� Ortho2D ������ ���� �ϴ��� 0,0 �̴�.
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex2i(250, 400);
//	glColor3f(0.0f, 1.0f, 1.0f);
//	glVertex2i(400, 100);
//	glEnd();
//
//}
//void draw_line(void)
//{
//	glLineWidth(15.0f);
//	glEnable(GL_LINE_STIPPLE);//��� state�� ON���� �ٲ���� ���Ϻ����� ����ȴ�.
//	glLineStipple(1, 0xAAAA); //factor = 1 , pattern = 0xAAAA��
//	/* ���� ������ ��������� */
//	glColor3f(0.5f, 1.0f, 0.5f);
//	glBegin(GL_LINES); //�� ���ڸ� GL_LINES�� �����������
//	glVertex2i(30, 30);
//	glVertex2i(30, 400);
//	glVertex2i(400, 30);
//	glVertex2i(30, 400);
//	glEnd();
//}
//void draw_triangle(void)
//{
//	/* ���� ������ ��������� */
//	glColor3f(0.7f, 0.5f, 0.3f);
//	glBegin(GL_TRIANGLE_STRIP);
//
//	glVertex2i(100, 100); 
//	glVertex2i(250, 250);
//	glVertex2i(20, 500);
//	glVertex2i(480, 0);
//	glVertex2i(480, 250);
//	glEnd();
//
//	glPointSize(10.0f);
//	glBegin(GL_POINTS); //gl Point�� ���� �׸��Ŷ�� ����
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glVertex2i(100, 100); //���⼭ �� vertex ������ rgb�� �ο��غ���
//	glColor3f(1.0f, 1.0f, 0.0f);
//	glVertex2i(250, 250);
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex2i(20, 500);
//	glColor3f(0.0f, 1.0f, 1.0f);
//	glVertex2i(480, 0);
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glVertex2i(480, 250);
//	glEnd();
//}
//
//void draw(void)
//{
//	/* ȭ���� �����ϰ� ����� */
//	glClear(GL_COLOR_BUFFER_BIT);
//	if (selected_menu == 21) draw_point();
//	if (selected_menu == 22) draw_line();
//	if (selected_menu == 23) draw_triangle();
//
//	if (enable_spin == true) {
//		glMatrixMode(GL_MODELVIEW); //��� Ȱ��ȭ
//		glLoadIdentity(); //���� Ȱ��ȭ�� ����� ������ķ� �ʱ�ȭ�Ѵ�.
//		glTranslatef(250, 250, 0); // 250,250�� pivot ����Ʈ�� ��⿡ �������� �̵��� 
//		glRotatef(spin, 0, 0, 1); // ���ϴ� ȸ�� ����(60��, z�����)���� ȸ���� ��
//		glTranslatef(-250, -250, 0); //�ٽ� ������� ���� �̵� �Ѵ�.
//	}
//	glFlush();
//	glutSwapBuffers(); // �갡 ����۸� ����Ʈ���۷� �ٲ��ִ� ������ ��
//}
//void mouse(int button, int state, int x, int y) {
//	/* ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ���� */
//	printf("Mouse button is clicked! (%d, %d, %d, %d)\n",
//		button, state, x, y);
//}
//void motion(int x, int y)
//{
//	/* ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ���� */
//	printf("Mouse is moving! (%d, %d)\n", x, y);
//}
//void keyboard(unsigned char key, int x, int y)
//{
//	/* ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ���� */
//	printf("You pressed %c\n", key);
//	if (key == 's') enable_spin = enable_spin ? false : true;
//}
//void idle(void) {
//	/* ���� ��ü�� ������(animation) ������ �̿�� ���� */
//	//printf("%d second has elapsed since the system was started\n", GetTickCount() / 1000);
//	spin = spin + 0.1;
//	if (spin > 360) spin -= 360;
//	glutPostRedisplay();
//}
//void sub_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	if (option == 2 ) enable_spin = enable_spin ? false : true;
//}
//void draw_menu_function(int option) {
//	printf("Drawmenu %d has been selected\n", option);
//	selected_menu = option;
//}
//void main_menu_function(int option)
//{
//	printf("Main menu %d has been selected\n", option);
//	if (option == 999) {
//		exit(0);
//	}
//}
//
//
//int main(int argc, char** argv)
//{
//	/* Window �ʱ�ȭ */
//	glutInit(&argc, argv);
//	int submenu1;
//	int drawmenu;
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init(); // -> ����� �ʱ�ȭ �Լ�
//	drawmenu = glutCreateMenu(draw_menu_function);
//	glutAddMenuEntry("Point", 21);
//	glutAddMenuEntry("Line", 22);
//	glutAddMenuEntry("Plane", 23);
//
//
//	submenu1 = glutCreateMenu(sub_menu_function);
//	glutAddSubMenu("Draw", drawmenu);
//	glutAddMenuEntry("Spin", 2);
//	glutAddMenuEntry("Sub3", 3);
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Go!", 11);
//	glutAddSubMenu("Sub Menu", submenu1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback �Լ� ���� */
//	//glutDisplayFunc(draw); /* draw() -> ���� �׸��� �Լ� */
//	glutDisplayFunc(draw);
//
//	glutMouseFunc(mouse);
//	glutMotionFunc(motion);
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idle);
//
//	/* Looping ���� */
//	glutMainLoop();
//	return 0;
//}
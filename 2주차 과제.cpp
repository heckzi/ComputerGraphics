//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//
//double spin = 0;
//int selected_menu = 0;
//bool enable_spin = 0;
//int x_move = 0;
//int y_move = 0;
//void init(void)
//{
//	/* ȭ���� �⺻���� black���� ���� */
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	/* ȭ�� ��ǥ ���� ���� */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f); //�궧���� ���� �ϴ��� 0,0�� �Ǵ� ����
//}
//void draw_point(void)
//{
//	/* ���� ������ ���� ������ */
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glPointSize(15.0f); //���� ũ�⸦ 15��
//	glBegin(GL_POINTS); //gl Point�� ���� �׸��Ŷ�� ����
//	glVertex2i(30 + x_move, 30 + y_move); //���� ��ġ ���� , �Ʊ� init�� Ortho2D ������ ���� �ϴ��� 0,0 �̴�.
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex2i(250 + x_move, 400 + y_move);
//	glColor3f(0.0f, 1.0f, 1.0f);
//	glVertex2i(400 + x_move, 100 + y_move);
//	glEnd();
//
//}
//void draw_line(void)
//{
//	glLineWidth(15.0f); //���� ���⸦ 15�� ����
//	glEnable(GL_LINE_STIPPLE);//��� state�� ON���� �ٲ���� ���Ϻ����� ����ȴ�.
//	glLineStipple(1, 0x00FF); //factor = 1 , pattern = 0x00FF��
//	/* ���� ���� ���� */
//	glColor3f(0.5f, 1.0f, 0.5f);
//	glBegin(GL_LINES); //�� ���ڸ� GL_LINES�� �����������
//	glVertex2i(150 + x_move, 150 + y_move);
//	glVertex2i(350 + x_move, 350 + y_move);
//	glVertex2i(150 + x_move, 350 + y_move);
//	glVertex2i(350 + x_move, 150 + y_move);
//	glEnd();
//}
//void draw_triangle(void)
//{
//	glFrontFace(GL_CCW); //�ո��� �޼����� ���Ҷ� ������ ���ϴ� ������
//	glDisable(GL_CULL_FACE);
//	/* ���� ������ ��������� */
//	glColor3f(0.7f, 0.5f, 0.3f);
//	glBegin(GL_TRIANGLES); //STRIP���� ������ �׸�
//	glVertex2i(100 + x_move, 120 + y_move);
//	glVertex2i(100 + x_move, 400 + y_move);
//	glVertex2i(400 + x_move, 400 + y_move);
//	glVertex2i(100 + x_move, 100 + y_move);
//	glVertex2i(400 + x_move, 100 + y_move);
//	glVertex2i(400 + x_move, 380 + y_move);
//	glEnd();
//
//	glPointSize(10.0f);
//	glBegin(GL_POINTS); //gl Point�� ���� �׸��Ŷ�� ����
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glVertex2i(100 + x_move, 120 + y_move); //���⼭ �� vertex ������ rgb�� �ο��غ���
//
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex2i(100 + x_move, 400 + y_move);
//
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glVertex2i(400 + x_move, 400 + y_move);
//
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glVertex2i(100 + x_move, 100 + y_move);
//
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex2i(400 + x_move, 100 + y_move);
//
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glVertex2i(400 + x_move, 380 + y_move);
//	glEnd();
//}
//void draw_polygon(void)
//{
//	glFrontFace(GL_CW); //�ո��� �޼����� ���Ҷ� ������ ���ϴ� ������
//	glPolygonMode(GL_FRONT, GL_FILL);
//	glCullFace(GL_FRONT);//�ո��� ���̵���
//	
//	glEnable(GL_CULL_FACE); 
//	glBegin(GL_POLYGON); //STRIP���� ������ �׸�
//	glColor3f(0.0f, 0.8f, 0.8f);
//	glVertex2i(100 + x_move, 100 + y_move);
//	glVertex2i(400 + x_move, 100 + y_move);
//	glVertex2i(400 + x_move, 300 + y_move);
//	glVertex2i(300 + x_move, 400 + y_move);
//	glVertex2i(200 + x_move, 300 + y_move);
//	glEnd();
//}
//void draw(void)
//{
//	/* ȭ���� �����ϰ� ����� */
//	glClear(GL_COLOR_BUFFER_BIT);
//	if (selected_menu == 21) draw_point();
//	if (selected_menu == 22) draw_line();
//	if (selected_menu == 23) draw_triangle();
//	if (selected_menu == 24) draw_polygon();
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
//void special_keyboard(int key, int x, int y)
//{
//	switch (key) {
//	case GLUT_KEY_LEFT:
//		x_move -= 5;
//		break;
//	case GLUT_KEY_RIGHT:
//		x_move += 5;
//		break;
//	case GLUT_KEY_UP:
//		y_move += 5;
//		break;
//	case GLUT_KEY_DOWN:
//		y_move -= 5;
//		break;
//	default:
//		break;
//	}
//}
//void idle(void) {
//	/* ���� ��ü�� ������(animation) ������ �̿�� ���� */
//	spin = spin + 0.1;
//	if (spin > 360) spin -= 360;
//	glutPostRedisplay();
//}
//void sub_menu_function(int option)
//{
//	printf("Submenu %d has been selected\n", option);
//	if (option == 2) enable_spin = enable_spin ? false : true;
//}
//void draw_menu_function(int option) {
//	printf("Drawmenu %d has been selected\n", option);
//	selected_menu = option;
//}
//void move_menu_function(int option) {
//	printf("Movemenu %d has been selected\n", option);
//	switch (option)
//	{
//	case 31:
//		x_move += 5;
//		break;
//	case 32:
//		x_move -= 5;
//		break;
//	case 33:
//		y_move += 5;
//		break;
//	case 34:
//		y_move -= 5;
//		break;
//	default:
//		break;
//	}
//}
//void main_menu_function(int option)
//{
//	printf("Main menu %d has been selected\n", option);
//	if (option == 999) {
//		exit(0);
//	}
//}
//
//int main(int argc, char** argv)
//{
//	/* Window �ʱ�ȭ */
//	glutInit(&argc, argv);
//	int submenu1;
//	int drawmenu;
//	int movemenu;
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init(); // -> ����� �ʱ�ȭ �Լ�
//
//	drawmenu = glutCreateMenu(draw_menu_function);
//	glutAddMenuEntry("Point", 21);
//	glutAddMenuEntry("Line", 22);
//	glutAddMenuEntry("Triangle", 23);
//	glutAddMenuEntry("PolyGon", 24);
//
//	movemenu = glutCreateMenu(move_menu_function);
//	glutAddMenuEntry("Move Right", 31);
//	glutAddMenuEntry("Move Left", 32);
//	glutAddMenuEntry("Move Up", 33);
//	glutAddMenuEntry("Move Down", 34);
//
//
//	submenu1 = glutCreateMenu(sub_menu_function);
//	glutAddSubMenu("Draw", drawmenu);
//	glutAddSubMenu("Move", movemenu);
//	glutAddMenuEntry("Spin", 2);
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Go!", 11);
//	glutAddSubMenu("Sub Menu", submenu1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback �Լ� ���� */
//	glutDisplayFunc(draw);
//	glutSpecialFunc(special_keyboard); //����� Ű����� �׷��� �� ������ �Է�
//	glutMouseFunc(mouse);
//	glutMotionFunc(motion);
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idle);
//
//	/* Looping ���� */
//	glutMainLoop();
//	return 0;
//}
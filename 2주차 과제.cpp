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
//	/* 화면의 기본색을 black으로 설정 */
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	/* 화면 좌표 정보 설정 */
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f); //얘때문에 좌측 하단이 0,0이 되는 것임
//}
//void draw_point(void)
//{
//	/* 점의 색상을 붉은 색으로 */
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glPointSize(15.0f); //점의 크기를 15로
//	glBegin(GL_POINTS); //gl Point로 점을 그릴거라고 선언
//	glVertex2i(30 + x_move, 30 + y_move); //점의 위치 설정 , 아까 init의 Ortho2D 때문에 좌측 하단이 0,0 이다.
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex2i(250 + x_move, 400 + y_move);
//	glColor3f(0.0f, 1.0f, 1.0f);
//	glVertex2i(400 + x_move, 100 + y_move);
//	glEnd();
//
//}
//void draw_line(void)
//{
//	glLineWidth(15.0f); //선의 굵기를 15로 설정
//	glEnable(GL_LINE_STIPPLE);//얘로 state를 ON으로 바꿔줘야 패턴변경이 적용된다.
//	glLineStipple(1, 0x00FF); //factor = 1 , pattern = 0x00FF로
//	/* 선의 색상 설정 */
//	glColor3f(0.5f, 1.0f, 0.5f);
//	glBegin(GL_LINES); //얘 인자를 GL_LINES로 변경해줘야함
//	glVertex2i(150 + x_move, 150 + y_move);
//	glVertex2i(350 + x_move, 350 + y_move);
//	glVertex2i(150 + x_move, 350 + y_move);
//	glVertex2i(350 + x_move, 150 + y_move);
//	glEnd();
//}
//void draw_triangle(void)
//{
//	glFrontFace(GL_CCW); //앞면을 왼손으로 감쌀때 엄지가 향하는 쪽으로
//	glDisable(GL_CULL_FACE);
//	/* 면의 색상을 노란색으로 */
//	glColor3f(0.7f, 0.5f, 0.3f);
//	glBegin(GL_TRIANGLES); //STRIP으로 도형을 그림
//	glVertex2i(100 + x_move, 120 + y_move);
//	glVertex2i(100 + x_move, 400 + y_move);
//	glVertex2i(400 + x_move, 400 + y_move);
//	glVertex2i(100 + x_move, 100 + y_move);
//	glVertex2i(400 + x_move, 100 + y_move);
//	glVertex2i(400 + x_move, 380 + y_move);
//	glEnd();
//
//	glPointSize(10.0f);
//	glBegin(GL_POINTS); //gl Point로 점을 그릴거라고 선언
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glVertex2i(100 + x_move, 120 + y_move); //여기서 각 vertex 색상을 rgb로 부여해보자
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
//	glFrontFace(GL_CW); //앞면을 왼손으로 감쌀때 엄지가 향하는 쪽으로
//	glPolygonMode(GL_FRONT, GL_FILL);
//	glCullFace(GL_FRONT);//앞면을 보이도록
//	
//	glEnable(GL_CULL_FACE); 
//	glBegin(GL_POLYGON); //STRIP으로 도형을 그림
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
//	/* 화면을 깨끗하게 지우기 */
//	glClear(GL_COLOR_BUFFER_BIT);
//	if (selected_menu == 21) draw_point();
//	if (selected_menu == 22) draw_line();
//	if (selected_menu == 23) draw_triangle();
//	if (selected_menu == 24) draw_polygon();
//	if (enable_spin == true) {
//		glMatrixMode(GL_MODELVIEW); //얘로 활성화
//		glLoadIdentity(); //현재 활성화된 행렬을 단위행렬로 초기화한다.
//		glTranslatef(250, 250, 0); // 250,250을 pivot 포인트로 삼기에 원점으로 이동후 
//		glRotatef(spin, 0, 0, 1); // 원하는 회전 각도(60도, z축기준)으로 회전한 후
//		glTranslatef(-250, -250, 0); //다시 원래대로 복귀 이동 한다.
//	}
//	glFlush();
//	glutSwapBuffers(); // 얘가 백버퍼를 프론트버퍼로 바꿔주는 역할을 함
//}
//void mouse(int button, int state, int x, int y) {
//	/* 인자들을 해석해서 원하는 기능을 구현 */
//	printf("Mouse button is clicked! (%d, %d, %d, %d)\n",
//		button, state, x, y);
//}
//void motion(int x, int y)
//{
//	/* 인자들을 해석해서 원하는 기능을 구현 */
//	printf("Mouse is moving! (%d, %d)\n", x, y);
//}
//void keyboard(unsigned char key, int x, int y)
//{
//	/* 인자들을 해석해서 원하는 기능을 구현 */
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
//	/* 추후 물체의 움직임(animation) 구현에 이용될 것임 */
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
//	/* Window 초기화 */
//	glutInit(&argc, argv);
//	int submenu1;
//	int drawmenu;
//	int movemenu;
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init(); // -> 사용자 초기화 함수
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
//	/* Callback 함수 정의 */
//	glutDisplayFunc(draw);
//	glutSpecialFunc(special_keyboard); //스페셜 키보드로 그려진 것 움직임 입력
//	glutMouseFunc(mouse);
//	glutMotionFunc(motion);
//	glutKeyboardFunc(keyboard);
//	glutIdleFunc(idle);
//
//	/* Looping 시작 */
//	glutMainLoop();
//	return 0;
//}
//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//#include<GL/freeglut.h>
//#include<cmath>
//
//int selected_menu = 0;
//double radius = 20;
//double theta = 45, phi = 45;
//double cam[3];
//double center[3] = { 0,0,0 };
//double up[3] = { 0,1,0 };
//const double pi = 3.14;
//
//void init(void)
//{
//	/* 화면의 기본색 설정 */
//	glClearColor(0.3f, 0.0f, 0.5f, 1.0f);
//	glMatrixMode(GL_PROJECTION);
//}
//void idle(void) {
//	if (phi >= 360 || phi <= -360)
//		phi = 0; //phi가 +-360도의 범위를 넘으면 0으로 만들어준다
//	if (cam[2] == 0) {
//		cam[2] = 1;
//		glutPostRedisplay();
//	}
//	if (cam[2] < 0 && up[1] == 1 || cam[2]>0 && up[1] == -1) {
//		up[1] *= -1; //cam[2]의 부호가 바뀌면 카메라의 y축 up벡터의 부호를 바꿔준다. 
//		glutPostRedisplay();
//	}
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
//void mousewheel(int button, int dir, int x, int y) {
//	if (dir > 0) {
//		printf("Zoom In, ");
//		radius -= 1;
//		glutPostRedisplay();
//	}
//	else {
//		printf("Zoom Out, ");
//		radius += 1;
//		glutPostRedisplay();
//	}
//	printf("Direction: %d Radius: %f\n", dir, radius);
//}
//void specialkeyboard(int key, int x, int y) {
//	char k[6];
//	switch (key) {
//	case GLUT_KEY_LEFT:
//		phi -= 1;
//		strcpy_s(k, "Left");
//		glutPostRedisplay();
//		break;
//	case GLUT_KEY_RIGHT:
//		phi += 1;
//		strcpy_s(k, "Right");
//		glutPostRedisplay();
//
//		break;
//	case GLUT_KEY_UP:
//		theta -= 1;
//		strcpy_s(k, "Up");
//		glutPostRedisplay();
//		break;
//	case GLUT_KEY_DOWN:
//		theta += 1;
//		strcpy_s(k, "Down");
//		glutPostRedisplay();
//		break;
//	default:
//		strcpy_s(k, "Nothing");
//		glutPostRedisplay();
//		break;
//	}
//	printf("%s Key Pressed  Phi : %f  Theta : %f\n", k, phi, theta);
//}
//void draw(void) // 기존 함수 변경
//{
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	cam[0] = radius * sin(theta * pi / 180) * cos(phi * pi / 180);
//	cam[1] = radius * cos(theta * pi / 180);
//	cam[2] = radius * sin(theta * pi / 180) * sin(phi * pi / 180);
//	gluLookAt(cam[0], cam[1], cam[2],
//		center[0], center[1], center[2], up[0], up[1], up[2]);
//	glColor3f(1, 1, 0);
//	glutWireTeapot(4);
//	draw_axis();
//	glFlush();
//}
//void main_menu_function(int option)
//{
//	printf("Main menu %d has been selected\n", option);
//	if (option == 999) {
//		exit(0);
//	}
//	if (option == 1) {
//		printf("Reset Teapot!\n");
//		radius = 20;
//		theta = 45;
//		phi = 45;
//		up[1] = 1;
//		glutPostRedisplay();
//	}
//}
//int main(int argc, char** argv)
//{
//	/* Window 초기화 */
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init(); // -> 사용자 초기화 함수
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Reset", 1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback 함수 정의 */
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutSpecialFunc(specialkeyboard);
//	glutMouseWheelFunc(mousewheel);
//	glutIdleFunc(idle);
//	/* Looping 시작 */
//	glutMainLoop();
//	return 0;
//}
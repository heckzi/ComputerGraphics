//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//#include<GL/freeglut.h>
//
//float sun_rot = 0;
//float planet_rot[5] = {}; //자전 각
//float planet_rev[5] = {}; //공전 각
//float moon_rot = 0;
//float moon_rev = 0;
//bool switch_rot = true;
//void idle(void)
//{ 
//	if (switch_rot == true) {
//	//지구의 하루동안 공전하는 각을 0.001으로 생각하고 대략 계산
//
//	//자전각도
//		sun_rot = sun_rot + 0.007; //태양
//		if (sun_rot > 360) sun_rot -= 360;
//		planet_rot[0] = planet_rot[0] + 0.00016; //수성
//		if (planet_rot[0] > 360) planet_rot[0] -= 360;
//		planet_rot[1] = planet_rot[1] + 0.00324; //금성
//		if (planet_rot[1] > 360) planet_rot[1] -= 360;
//		planet_rot[2] = planet_rot[2] + 0.036; //지구
//		if (planet_rot[2] > 360) planet_rot[2] -= 360;
//		planet_rot[3] = planet_rot[3] + 0.00099; //화성
//		if (planet_rot[3] > 360) planet_rot[3] -= 360;
//		moon_rot = moon_rot + 0.00075; //달
//		if (moon_rot > 360) moon_rot -= 360;
//
//		//공전각도
//		planet_rev[0] = planet_rev[0] + 0.00415; //수성
//		if (planet_rev[0] > 360) planet_rev[0] -= 360;
//		planet_rev[1] = planet_rev[1] + 0.00324; //금성
//		if (planet_rev[1] > 360) planet_rev[1] -= 360;
//		planet_rev[2] = planet_rev[2] + 0.001; //지구
//		if (planet_rev[2] > 360) planet_rev[2] -= 360;
//		planet_rev[3] = planet_rev[3] + 0.0005; //화성
//		if (planet_rev[3] > 360) planet_rev[3] -= 360;
//		moon_rev = moon_rev + 0.00083; //달
//		if (moon_rev > 360) moon_rev -= 360;
//	}
//	
//	glutPostRedisplay();
//}
//
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
//void draw(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(15, 15, 15, 0, 0, 0, 0, 1, 0);
//
//	//태양 그리기
//	glRotatef(sun_rot, 0, 1, 0);
//	glColor3f(1, 0, 0);
//	glutWireSphere(2.0, 50, 50);
//	draw_axis();
//	glPushMatrix();
//
//	//수성 그리기
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[0], 0, 1, 0);
//	glTranslatef(2, 0, 0);
//	glRotatef(planet_rot[0], 0, 1, 0);
//	glColor3f(0.3, 0.6, 0);
//	glutWireSphere(0.3, 50, 50);
//
//	//금성 그리기
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[1], 0, 1, 0);
//	glTranslatef(4, 0, 0);
//	glRotatef(planet_rot[1], 0, 1, 0);
//	glColor3f(0.4, 0.6, 0.5);
//	glutWireSphere(0.3, 50, 50);
//
//	//지구 그리기
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[2], 0, 1, 0);
//	glTranslatef(6, 0, 0);
//	glRotatef(planet_rot[2], 0, 1, 0);
//	glColor3f(0, 0.1, 0.9);
//	glutWireSphere(1.0, 50, 50);
//
//	//달 그리기
//	glRotatef(moon_rev, 0, 1, 0); 
//	glTranslatef(1, 0, 0); 
//	glRotatef(moon_rot, 0, 1, 0); 
//	glColor3f(0, 0.5, 1); 
//	glutWireSphere(0.2, 50, 50);
//
//	//화성 그리기
//	glPopMatrix();
//	glRotatef(planet_rev[3], 0, 1, 0);
//	glTranslatef(8, 0, 0);
//	glRotatef(planet_rot[3], 0, 1, 0);
//	glColor3f(1.0, 0, 0.3);
//	glutWireSphere(1.0, 50, 50);
//
//	glFlush();
//	glutSwapBuffers();
//}
//void main_menu_function(int option)
//{
//	if (option == 999) {
//		printf("Quit menu has been selected\n");
//		exit(0);
//	}
//	if (option == 1) {
//		printf("Rotate Switch menu has been selected\n");
//		switch_rot = switch_rot ? false : true;
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
//	glutCreateWindow("12191781 손혁진 6주차");
//	init(); // -> 사용자 초기화 함수
//
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Rotate Switch", 1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback 함수 정의 */
//	glutIdleFunc(idle);
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	/* Looping 시작 */
//	glutMainLoop();
//	return 0;
//}
//

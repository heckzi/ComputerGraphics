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
//int light_state = 0;
//void idle(void)
//{
//	if (switch_rot == true) {
//		//지구의 하루동안 공전하는 각을 0.001으로 생각하고 대략 계산
//
//		//자전각도
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
//void keyboard(unsigned char key, int x, int y)
//{
//	/* 인자들을 해석해서 원하는 기능을 구현 */
//	printf("You pressed %c\n", key);
//	if (key == '0') light_state = 0;
//	if (key == '1') light_state = 1; //태양
//	if (key == '2') light_state = 2; //지구
//	if (key == '3') light_state = 3; //달
//	if (key == '4') light_state = 4; 
//}
//void init(void)
//{
//	/* 화면의 기본색으로 dark blue 설정 */
//	glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);
//	glClearColor(0.3f, 0.0f, 0.5f, 1.0f);
//	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
//	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	//GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//카메라 위치에 광원 위치 하게
//	// glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0); //cutoff 하는 곳
//	// GLfloat spot_direction[] = { 1.0, 0.0, 1.0, 0.0 }; 
//	// glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
//	// glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 3.0);
//
//	//glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 2.0); // 감쇄속성
//
//	// 재질의 반사 특성 설정 – init()에 추가
//	GLfloat ambient_Sun[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat diffuse_Sun[] = { 1.0f, 0.0f, 0.0f, 1.0f }; //빨간색의 빛색깔
//	GLfloat specular_Sun[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_Sun);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_Sun);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_Sun);
//	glMaterialf(GL_FRONT, GL_SHININESS, 64);
//	glColor3f(0, 0, 0);
//	draw_string(GLUT_BITMAP_HELVETICA_18, "12191781 손혁진", 10, 10);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialf(GL_FRONT, GL_SHININESS, 64);
//
//	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); //색깔 살리게
//	//glEnable(GL_COLOR_MATERIAL);	
//
//	glMatrixMode(GL_PROJECTION);
//	//
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
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(15, 15, 15, 0, 0, 0, 0, 1, 0);
//
//
//	if (light_state == 0) {
//		GLfloat light_position[] = { 15.0, 15.0, 15.0, 1.0 };//카메라에 광원 위치하게
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	}
//	if (light_state == 1) {
//		GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position);//태양의 중심에 광원위치하게
//	}
//	glRotatef(sun_rot, 0, 1, 0);
//	glColor3f(1, 0, 0);
//
//	//GLfloat emission1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	//glMaterialfv(GL_FRONT, GL_EMISSION, emission1);
//
//	glutSolidSphere(2.0, 50, 50);//태양 그리기
//
//	//emission1[0] = 0.0f;
//	//glMaterialfv(GL_FRONT, GL_EMISSION, emission1);
//
//	draw_axis();
//	glPushMatrix();
//
//	//수성 그리기
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[0], 0, 1, 0);
//	glTranslatef(3, 0, 0);
//	glRotatef(planet_rot[0], 0, 1, 0);
//	glColor3f(0.3, 0.6, 0);
//	glutSolidSphere(0.3, 50, 50);
//
//	//금성 그리기
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[1], 0, 1, 0);
//	glTranslatef(4, 0, 0);
//	glRotatef(planet_rot[1], 0, 1, 0);
//	glColor3f(0.4, 0.6, 0.5);
//	glutSolidSphere(0.3, 50, 50);
//
//	//지구 그리기
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[2], 0, 1, 0);
//	glTranslatef(6, 0, 0);
//	glRotatef(planet_rot[2], 0, 1, 0);
//	if (light_state == 2) {
//		GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position);//지구의 중심에 광원위치하게
//	} 
//	glColor3f(0, 0.1, 0.9);
//
//	//GLfloat emission2[] = { 0.0f, 0.0f, 1.0f, 1.0f };
//	//glMaterialfv(GL_FRONT, GL_EMISSION, emission2);
//
//	glutSolidSphere(1.0, 50, 50);
//
//	//emission2[0] = 0.0f;
//	//glMaterialfv(GL_FRONT, GL_EMISSION, emission2);
//
//	//달 그리기
//	glRotatef(moon_rev, 0, 1, 0);
//	glTranslatef(1.5, 0, 0);
//	glRotatef(moon_rot, 0, 1, 0);
//	if (light_state == 3) {
//		GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position);//달의 중심에 광원위치하게
//	}
//	glColor3f(0, 0.5, 1);
//
//	//GLfloat emission3[] = { 0.0f, 1.0f, 1.0f, 1.0f };
//	//glMaterialfv(GL_FRONT, GL_EMISSION, emission3);
//
//	glutSolidSphere(0.2, 50, 50);
//
//	//emission3[0] = 0.0f;
//	//glMaterialfv(GL_FRONT, GL_EMISSION, emission3);
//
//	//화성 그리기
//	glPopMatrix();
//	glRotatef(planet_rev[3], 0, 1, 0);
//	glTranslatef(9, 0, 0);
//	glRotatef(planet_rot[3], 0, 1, 0);
//	glColor3f(1.0, 0, 0.3);
//	glutSolidSphere(1.0, 50, 50);
//
//	if (light_state == 4) {
//		GLfloat light_position[] = { 1000.0, 0.0, 0.0, 1.0 };
//		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	}
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
//	glutCreateWindow("12191781 손혁진 11주차");
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
//	glutKeyboardFunc(keyboard);
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	/* Looping 시작 */
//	glutMainLoop();
//	return 0;
//}
//


/*
*	����MFC��ؿ�
*/

/**
*	created on 2017-1-1
*	author ������
*
*	opengl ������	
*	Ӧ����MFC
*/


#ifndef _BASECOMPATGL_H_
#define _BASECOMPATGL_H_

#include <windef.h>
#include <afxwin.h>
#include <glm/glm.hpp>

class BaseCompatGL{

public:

	BaseCompatGL(void);
	~BaseCompatGL(void);

	/*
	*	��MFC��CView���д���OpenGL��Ⱦ����	
	*
	*	��MFC�е�View����붨��
	*	HGLRC	m_hRC;	 
	*	CClientDC*	m_pDC;
	*	����Ϊ��������
	*/
	BOOL createContext(CView* pView);
	BOOL deleteContext(void);

	/*	��ȡ�豸������л��� */
	CClientDC* getClientDC(void);

	//���ñ�����ɫ
	void setBackgroundColor(GLfloat red, GLfloat green, GLfloat blue);
	void setBackgroundColorTop(GLfloat red, GLfloat green, GLfloat blue);
	void setBackgroundColorBottom(GLfloat red, GLfloat green, GLfloat blue);

	//OpenGL����س�ʼ��
	void init(void);

	// ���Ʒ����� ���������ʵ��
	virtual void draw(void) = 0;
	
protected:

	//���Ʊ���
	void drawBackground(void);

	//�û�˫���� SwapBuffers()
	void show(void);


private:
	//OpenGL���Ƶ���ͼ������
	CView* m_pView;

	HGLRC m_hRC;
	CClientDC* m_pDC;

	glm::vec3 m_backgroundColorTop;
	glm::vec3 m_backgroundColorBottom;

	//��ʼ������
	void initLighting(void);
};




#endif
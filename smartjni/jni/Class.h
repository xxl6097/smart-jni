/*
 * Class.h
 *
 *  Created on: 2012-12-16
 *      Author: boyliang
 */

#ifndef CLASS_H_
#define CLASS_H_

#include <jni.h>

namespace smart_jni{

class Method;
class Field;

class Class {

private:
	static jmethodID s_Class_getName_ID;

protected:
	jclass mClass;

	Class(const char* name);
	Class(const jclass claxx);
	Class(const Class& claxx);

	static char* trans2JNIName(const char* name);
	static jclass trans2Primitive(const jclass claxx);

public:
	/**
	 * ���ݷ������Լ����������ҷ���
	 */
	Method* getMethod(const char* methodname, ...) const;

	/**
	 * �����ֶ���,�����ֶ�
	 */
	Field* getField(const char* filedname) const;

	/**
	 * ��ȡ������
	 */
	const char* getName();

	/**
	 * ��ȡjclass����
	 */
	const jclass getJNIClass();

	/**
	 *  checking self is assignable from the claxx
	 */
	bool isAssignableFrom(const Class& claxx);

	/**
	 * ����
	 */
	virtual ~Class();

	/**
	 * ��ȡ�û��Զ���Class
	 */
	static Class* forName(const char* name);

	/**
	 * ��ȡ�ִ�����ȡClass
	 */
	static Class* forObject(const jobject object);

	/**
	 * ������β
	 */
	static const Class* END;
};

}


#endif /* CLASS_H_ */

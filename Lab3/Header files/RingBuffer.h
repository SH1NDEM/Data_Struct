#pragma once

//! \brief ��������� �����.
struct RingBuffer
{
private:
	//! \brief ��������� �� ����� ������.
	int* _buffer;   

	//! \brief ������ ������ ������.
	int _head;

	//! \brief ������ ������ ������.
	int _tail;

	//! \brief ������ ������.
	int _size;

	//! \brief ����, ����������� �� ������������� ������.
	bool _isFull;       

public:
	//! \brief �����������. ������� ��������� ����� ��������� �������.
	//! \param size ������ ������.
	RingBuffer(int size);

	//! \brief ����������� ������, ���������� ��� �����.
	~RingBuffer();

	//! \brief ��������� ������� � ����� ������.
	//! \param value ��������, ������� ����� ��������.
	void Push(int value);

	//! \brief ��������� � ���������� ������� �� ������ ������.
	//! \return �������� ������������ ��������.  ����������� ��������� ������ ��� ������� ������.
	int Pop();

	//! \brief ���������, ���� �� �����.
	//! \return true, ���� ����� ����, false � ��������� ������.
	bool IsEmpty() const;

	//! \brief �������� ������ ������.
	//! \param newSize ����� ������ ������. ����������� ������ newSize <= 0.
	void Resize(int newSize);

	//! \brief ���������� ������� ������ ������.
	//! \return ������� ������ ������.
	int GetSize() const;

	//! \brief ���������� ���������� ���������� ����� � ������.
	//! \return ���������� ���������� ����� � ������.
	int GetFreeSpace() const;

	//! \brief ���������� ���������� ������� ����� � ������.
	//! \return ���������� ������� ����� � ������.
	int GetUsedSize() const;
};
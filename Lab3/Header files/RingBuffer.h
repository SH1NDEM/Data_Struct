#pragma once

//! \brief Кольцевой буфер.
struct RingBuffer
{
private:
	//! \brief Указатель на буфер данных.
	int* _buffer;   

	//! \brief Индекс головы буфера.
	int _head;

	//! \brief Индекс хвоста буфера.
	int _tail;

	//! \brief Размер буфера.
	int _size;

	//! \brief Флаг, указывающий на заполненность буфера.
	bool _isFull;       

public:
	//! \brief Конструктор. Создает кольцевой буфер заданного размера.
	//! \param size Размер буфера.
	RingBuffer(int size);

	//! \brief Освобождает память, выделенную под буфер.
	~RingBuffer();

	//! \brief Добавляет элемент в конец буфера.
	//! \param value Значение, которое нужно добавить.
	void Push(int value);

	//! \brief Извлекает и возвращает элемент из начала буфера.
	//! \return Значение извлеченного элемента.  Рассмотрите обработку ошибки для пустого буфера.
	int Pop();

	//! \brief Проверяет, пуст ли буфер.
	//! \return true, если буфер пуст, false в противном случае.
	bool IsEmpty() const;

	//! \brief Изменяет размер буфера.
	//! \param newSize Новый размер буфера. Обработайте случай newSize <= 0.
	void Resize(int newSize);

	//! \brief Возвращает текущий размер буфера.
	//! \return Текущий размер буфера.
	int GetSize() const;

	//! \brief Возвращает количество свободного места в буфере.
	//! \return Количество свободного места в буфере.
	int GetFreeSpace() const;

	//! \brief Возвращает количество занятых ячеек в буфере.
	//! \return Количество занятых ячеек в буфере.
	int GetUsedSize() const;
};
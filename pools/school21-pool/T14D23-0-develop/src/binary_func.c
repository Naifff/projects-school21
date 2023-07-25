#include "binary_func.h"

// Читаем запись из файла конкретного типа по порядковому номеру
struct my_struct read_record_from_file(FILE *pfile, int index) {
    // Считаем смещение позиции искомой записи относительно начала файла
    int offset = index * sizeof(struct my_struct);
    // Двигаем указатель на нужное смещение
    fseek(pfile, offset, SEEK_SET);

    // Читаем нужную запись
    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);

    // Возвращаем указатель в начало файла
    rewind(pfile);

    // Возвращаем запись
    return record;
}

// Вносим запись конкретного типа в файл по указанной позиции
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index) {
    // Вычисляем смещение
    int offset = index * sizeof(struct my_struct);
    // Двигаем указатель на смещение
    fseek(pfile, offset, SEEK_SET);

    // Вносим запись в файл
    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);

    // Записываем содержимое буфера в файл
    fflush(pfile);

    // указатель в начало файла
    rewind(pfile);
}

// Меняем записи местами
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    // Считываем обе записи в переменные
    struct my_struct record1 = read_record_from_file(pfile, record_index1);
    struct my_struct record2 = read_record_from_file(pfile, record_index2);

    // Перезаписать их в файл
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

// Получаем размер файла в битах
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);    // Перемещаем указатель в конец файла
    size = ftell(pfile);          // Считаем количество байтов до указателя
    rewind(pfile);                // Возвращаем указатель в начало файла
    return size;
}

// Получаем количество записей в файле
int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct my_struct);
}

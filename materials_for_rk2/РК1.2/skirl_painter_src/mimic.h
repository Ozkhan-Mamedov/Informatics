/// @file mimic.h
/// @brief Заголовочный файл библиотеки Mimic.
/// @author Каранкевич Антон Александрович. НИИ РЭТ МГТУ им. Баумана.
///
/// Библиотека Mimic представляет собой гибкий тип данных с динамической
/// типизацией. Данный тип может хранить, принимать и представлять значения
/// следующих типов языка С++:
/// - boolean
/// - int (int32_t)
/// - long int (int64_t)
/// - float
/// - double
/// - complex double
/// - char[]
/// - void*
/// .
/// Хранимые данные могут быть организованы в виде массива произвольного
/// размера. Возможно изменение размера массива хранимых данных и их типа
/// в процессе работы.


#ifndef MIMIC_H
#define MIMIC_H

#define __STDC_LIMIT_MACROS

#include <complex>
#include <_stdint.h>

#define CHARSIZE 1024           ///< Размер строкового буфера


/// @brief Комплексные данные
///
/// Комплексная переменная в стандартном виде.
typedef std::complex<double> cdouble;

/// @brief Типы данных
///
/// Типы данных, доступные для метатипа.
enum dataType {
  DT_NOPE,          ///< Вообще не данные (тип ошибочен)
  DT_BOOL,          ///< 1 бит (bool)
//  DT_BYTE,          // 1 целочисленный байт
//  DT_SHORT,         // 2 целочисленных байта
  DT_INT,           ///< 4 целочисленных байта (int32_t)
  DT_LONG,          ///< 8 целочисленных байт (int64_t)
  DT_FLOAT,         ///< 4 вещественных байта (float)
  DT_DOUBLE,        ///< 8 вещественных байт (double)
  DT_COMPLEX,       ///< 2х8 вещественных байт комплексного числа (cdouble)
  DT_STRING,        ///< Строка как есть (char[])
  DT_RAW            ///< Сырые данные (void*)
};

// Дефайны C-типов, соответствующих типам выше
#define TYPE_BOOL       bool
#define TYPE_INT        int32_t
#define TYPE_LONG       int64_t
#define TYPE_FLOAT      float
#define TYPE_DOUBLE     double
#define TYPE_COMPLEX    cdouble

/// @brief Класс, являющийся основой библиотеки.
///
/// Данный класс является основой библиотеки и представляет собой средство
/// хранения произвольных данных с динамической типизацией.
///
/// Основным методом класса является метод @ref set(), представленный в виде
/// нескольких полиморфных версий, и методы @ref toInt(), @ref toDouble(),
/// @ref toCString() и прочие, предоставляющие хранимые данные в требуемом виде.
///
/// Тип данных, хранимых в классе Mimic, задается при помощи процедуры
/// @ref setType() и может быть получен функцией @ref getType(). Рекомендуется
/// передавать и получать данные в том же типе, который был задан, хотя это и не
/// обязательно.
///
/// Процедуры @ref setType() и @ref setNumVars() производят перераспределение
/// массива данных динамически, и могут быть вызваны в любой момент. Следует
/// однако учесть, что перевод данных возможен только между численными типами,
/// и при этом перевод из вещественного типа в целый теряет дробную часть.
///
/// В процедуре @ref set() происходит автоматическая проверка на границы массива
/// и на пределы значений переменной.
class Mimic
{
public:
    Mimic(int num=1         ///< Число элементов в массиве.
          );
    ///< Конструктор. Используются следующие значения параметров по умолчанию:
    ///  - type = DT_NOPE
    ///  - high = DBL_MAX;
    ///  - low = DBL_MIN
    ///  - paramName = ""
    ///

    Mimic(dataType t,       ///< Тип хранимых переменных.
          int num=1         ///< Число элементов в массиве.
          );
    ///< Конструктор. Используются следующие значения параметров по умолчанию:
    ///  - high = DBL_MAX;
    ///  - low = DBL_MIN
    ///  - paramName = ""
    ///

    Mimic(dataType t, double h, double l, int num=1);
    ///< Конструктор. Используются следующие значения параметров по умолчанию:
    ///  - paramName = ""
    ///  - description = ""
    ///

    Mimic(dataType t, const char *name, int num=1);
    ///< Конструктор. Используются следующие значения параметров по умолчанию:
    ///  - high = DBL_MAX;
    ///  - low = DBL_MIN
    ///

    Mimic(dataType t, const char *name, double h, double l, int num=1);
    ///< Конструктор с максимальным набором задаваемых параметров.
    ///

    ~Mimic();

    void setType(dataType t);
    ///< Задает тип переменной. При наличии данных производится переконвертация
    ///  из одного типа данных в другой.
    ///  @warning Преобразование возможно только между численными данными.
    ///           Преобразование из вещественного типа в целочисленный приведет
    ///           к потере дробной части.

    void setHigh(double h);
    ///< Задает верхний предел значения переменной. Актуально только для
    ///  численных типов.

    void setLow(double l);
    ///< Задает нижний предел значения переменной. Актуально только для
    ///  численных типов.

    void setNumVars(int n);
    ///< Задает число переменных в массиве. Перезаводит массив данных для
    ///  соответствия нужной длине

    void setParamName(const char *name);
    ///< Задает имя параметра. Можно использовать его как имя параметра в
    ///  ini-файле, либо для вывода на экран.

    void setDesc(const char *name);
    ///< Задает описание параметра. Произвольная форма.
    ///


    //----------------//
    //     get'ы      //
    //----------------//

    dataType    getType();
    ///< Возвращает тип паременной.

    double      getHigh();
    ///< Возвращает верхний предел значения.

    double      getLow();
    ///< Возвращает нижний предел значения.

    int         getNumVars();
    ///< Возвращает число переменных в массиве.

    char*       getName();
    ///< Возвращает имя параметра в виде указателя на строку (char*).

    char*       getDesc();
    ///< Возвращает описание параметра в виде указателя на строку (char*).

    bool        isSingleReal();
    ///< Возвращает, является ли тип простым вещественным числом

    bool        isSingleInt();
    ///< Возвращает, является ли тип простым целым числом


    //-----------------//
    // Выдача значений //
    //-----------------//

    void*       toRawData();
    ///< Выдает сырые данные как они есть. Работает абсолютно со всеми типами
    ///  данных. В случае @ref DT_STRING вернет нулевой указатель, так как
    ///  строка хранится статически.
    /// @return Указатель на сырые данные в виде void*.

    TYPE_BOOL   toBool  (int index=0);
    ///< Возвращает переменную по указанному индексу в булевом виде.
    ///  По умолчанию используется значение index = 0.
    /// @return Значение переменной с индексом index. Булевый тип.

//    char        toChar  (int index=0);
//    short int   toShort (int index=0);

    TYPE_INT    toInt   (int index=0);
    ///< Возвращает переменную по указанному индексу в целочисленном виде.
    ///  По умолчанию используется значение index = 0.
    /// @return Значение переменной с индексом index. Целый тип (int).

    TYPE_LONG   toLong  (int index=0);
    ///< Возвращает переменную по указанному индексу в длинном целочисленном
    /// виде. По умолчанию используется значение index = 0.http://lurkmore.ru/images/9/98/7fce7ffd556f.jpg
    /// @return Значение переменной с индексом index. Длинный целый тип
    ///         (long int).

    TYPE_FLOAT  toFloat (int index=0);
    ///< Возвращает переменную по указанному индексу в вещественном виде.
    ///  По умолчанию используется значение index = 0.
    /// @return Значение переменной с индексом index. Вещественный тип (float).

    TYPE_DOUBLE toDouble(int index=0);
    ///< Возвращает переменную по указанному индексу в длинном вещественном
    /// виде. По умолчанию используется значение index = 0.
    /// @return Значение переменной с индексом index. Длинный Целый тип
    ///         (double).

    TYPE_COMPLEX toComplex(int index=0);
    ///< Вощвращает переменную в комплексном виде (complex<double>, cdouble).
    ///  По умолчанию испольщуется значение index = 0.
    /// @return Значение переменной с индексом index. Комплексный тип
    ///         (Comp).

    char*       toCString(int index=0, ///< Начальный индекс элементов массива.
                          int amount=1, ///< Число отображаемых элементов.
                          const char* delimiter = " " ///< Строковый разделитель.
                         );
    ///< Возвращает текстовую строку, в которую записаны значения элементов
    ///  массива начиная с номера index в количестве amount. Между элементами
    ///  вставляется разделитель delimiter. По умолчанию index = 0, amount = 1,
    ///  delimiter = " ". При указании значения amount меньше 0 происходит вывод
    ///  всех элементов массива.
    /// @return Указатель на статическую строку в теле класса, в которую
    ///         записана результирующая строка. Максимальная длина возвращаемой
    ///         строки ограничена значением макроса @ref CHARSIZE.

// Доделать в следующей версии
//    void        toCString(char *str, int str_l, int index=0, int amount=1,
//                          char *delimiter = " ");

    //-----------------//
    //      set'ы      //
    //-----------------//

    void setRaw(void* ptr, ///< Указатель на сырые данные.
                int size   ///< Размер сырых данных в байтах.
               );
    ///< Задание непосредственно сырых данных. Работает со всеми типами, кроме
    ///  @ref DT_STRING.
    ///  @warning Не рекомендуется применять с каким-либо типом данных, кроме
    ///  @ref DT_RAW, если вы не уверены, что вы делаете.

    // Задание значения (перегрузка)

    void set(TYPE_BOOL b,        ///< Задаваемое значение.
             int index=0    ///< Индекс элемента.
            );
    ///< Задание значения элемента с определенным индексом в булевом виде.
    ///  Проверка на границы массива происходит автоматически.

//    void set(char c, int index=0);
//    void set(short int s, int index=0);
    void set(TYPE_INT i,         ///< Задаваемое значение.
             int index=0    ///< Индекс элемента.
            );
    ///< Задание значения элемента с определенным индексом в целочисленном виде.
    ///  Проверка на границы массива и пределы значений происходит
    ///  автоматически.

    void set(TYPE_LONG l,    ///< Задаваемое значение.
             int index=0    ///< Индекс элемента.
            );
    ///< Задание значения элемента с определенным индексом в длинном
    ///   целочисленном виде. Проверка на границы массива и пределы значений
    ///   происходит автоматически.

    void set(TYPE_FLOAT f,       ///< Задаваемое значение.
             int index=0    ///< Индекс элемента.
            );
    ///< Задание значения элемента с определенным индексом в вещественном виде.
    ///  Проверка на границы массива и пределы значений происходит
    ///  автоматически.

    void set(TYPE_DOUBLE d,      ///< Задаваемое значение.
             int index=0    ///< Индекс элемента.
            );
    ///< Задание значения элемента с определенным индексом в длинном
    ///  вещественном виде. Проверка на границы массива и пределы значений
    ///  происходит автоматически.

    void set(TYPE_COMPLEX d,        ///< Задаваемое значение.
             int index=0    ///< Индекс элемента.
            );
    ///< Задание значения элемента с определенным индексом в комплексном
    ///  вещественном виде. Проверка на границы массива происходит
    ///  автоматически.

    void set(const char *str,          ///< Указатель на строку, содержащую значения.
             int index=0,        ///< Индекс элемента массива.
             bool bWipe = false  ///< Вычистить ли весь остальной массив в нули?
            );
    ///< Задание значения элементов массива при помощи строки. В случае типа
    ///  @ref DT_STRING строка копируется напрямую. В остальных случаях
    ///  происходит ее интерпретация.
    ///
    ///  Подразумевается, что строка представляет собой значения, разделенные
    ///  пробелами или знаками ';', причем значение index указывает на индекс
    ///  того элемента массива, который должен соответствовать первому
    ///  записанному в строке. К примеру, параметры str = "1 2 4.5" и index = 2
    ///  зададут элементам 2, 3 и 4 значения 1, 2 и 4.5 соответственно.
    ///  Проверка на выход за границы массива и пределы значений переменных
    ///  производится автоматически.


private:
    char        paramName[CHARSIZE];    ///< Имя параметра(в т.ч. в ini-файле).
    dataType    type;                   ///< Тип данных.
    int         numVars;                ///< Число элементов. По умолчанию 1.
    double      high;                   ///< Верхнее значение (для числовых).
    double      low;                    ///< Нижнее значение (для числовых).

    void*       dataptr;                ///< Указатель на данные.
    size_t      datasize;               ///< Размер массива данных.
    char        chardata[CHARSIZE];     ///< @brief Строка-запись (для DT_STRING
                                        ///  и преобразования в строку).
    char        description[CHARSIZE];  ///< Мелкое строковое описание.

    void        flushParams();          ///< Сброс всех параметров в нули.
    size_t      varsize();              ///< Возвращает размер переменной [Б].

    TYPE_INT    limitValue(TYPE_INT i);     ///< Вписывает значение в пределы.
    TYPE_LONG   limitValue(TYPE_LONG i);    ///< Вписывает значение в пределы.
    TYPE_FLOAT  limitValue(TYPE_FLOAT i);   ///< Вписывает значение в пределы.
    TYPE_DOUBLE limitValue(TYPE_DOUBLE i);  ///< Вписывает значение в пределы.
    TYPE_COMPLEX limitValue(TYPE_COMPLEX i);///< Вписывает значение в пределы.
    void        unbound();              ///< Растягивает пределы до диапазона
                                        ///  переменной.

};

#endif // MIMIC_H

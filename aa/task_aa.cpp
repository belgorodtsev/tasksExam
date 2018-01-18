float mean(const std::vector<float>& v)
{
    float sum = 0;
    for (float f : v)
        sum += f;
    return sum / v.size();
}
std::pair<float, float> minMax(const std::vector<float>& v)
{
    float min = v[0];
    float max = v[0];
    for (float f : v)
    {
        if (f <= min)       
            min = f;
        if (f >= max)
            max = f;
    }
    return std::make_pair(min, max);
}
int argmax(const std::vector<float>& v)
{
    float max = v[0];
    int index = 0;
    for (int i = 0; i < v.size(); ++i)
        if (v[i] >= max)
        {
            max = v[i];
            index = i;
        }
    return index;
}
const std::vector<float>::iterator argm(std::vector<float>& v)
{
    float max = v[0];
    std::vector<float>::iterator a = v.begin();
    std::vector<float>::iterator tmp;
    for (a; a != v.end(); ++a)
        if (*a >= max)
        {
            max = *a;
            tmp = a;
        }
    return tmp;
}

using VIterator = std::vector<int>::iterator;
VIterator findInSorted(VIterator first, VIterator last, int val)
{
    const  VIterator end = last;
    if ((std::distance(first, last) == 0) || (*first > val) || (*(last - 1) < val))
        return end;
    while (std::distance(first, last) > 0)
    {
        const VIterator mid = first + std::distance(first, last) / 2;
        if (val <= *mid)
        {
            last = mid;
        }
        else
        {
            first = mid + 1;
        }
        return first;
    }
}

struct Matrix
{
    float ** matrix;
    int n;
    int m;
};

Matrix newMatrix(int N, int M)
{
    Matrix m;
    m.matrix = new float*[N];
    for (int i = 0; i < N; ++i)    
        m.matrix[i] = new float[M];
    m.n = N;
    m.m = M;
    return m;
}
// удаление
void deleteMatrix(Matrix& m)
{
    for (int i = 0; i < m.n; ++i)
        delete[] m.matrix[i];
    delete[] m.matrix;
    m.matrix = nullptr;
    m.n = 0;
    m.m = 0;
}
// максимальный элемент матрицы
float max(const Matrix& m)
{
    float max = m.matrix[0][0];
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.m; ++j)
            if (m.matrix[i][j] >= max)
                max = m.matrix[i][j];      
    return max;
}
// индекс максимального элемента
std::pair<int, int> argmax(const Matrix& m)
{
    int indexI = 0;
    int indexJ = 0;
    float max = m.matrix[0][0];
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.m; ++j)
            if (m.matrix[i][j] >= max)
            {
                max = m.matrix[i][j];
                indexI = i;
                indexJ = j;
            }
    return std::make_pair(indexI, indexJ);
}
// минимальный элемент
float min(const Matrix& m)
{
    float min = m.matrix[0][0];
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.m; ++j)
            if (m.matrix[i][j] <= min)
                min = m.matrix[i][j];
    return min;
}
// индекс минимального
std::pair<int, int> argmin(const Matrix& m)
{
    int indexI = 0;
    int indexJ = 0;
    float min = m.matrix[0][0];
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.m; ++j)
            if (m.matrix[i][j] <= min)
            {
                min = m.matrix[i][j];
                indexI = i;
                indexJ = j;
            }
    return std::make_pair(indexI, indexJ);
}
// максимальные элементы в строках
std::vector<float> maxStrok(const Matrix& m)
{
    std::vector<float> v;  
    for (int i = 0; i < m.n; ++i)
    {
        float max = m.matrix[i][0];
        for (int j = 0; j < m.m; ++j)
            if (m.matrix[i][j] >= max)            
                max = m.matrix[i][j];
        v.push_back(max);
    }
    return v;
}
// максимальные элементы в столбцах
std::vector<float> maxStolb(const Matrix& m)
{
    std::vector<float> v;
    for (int j = 0; j < m.m; ++j)
    {
        float max = m.matrix[0][j];
        for (int i = 0; i < m.n; ++i)
        {     
            if (m.matrix[i][j] >= max)
                max = m.matrix[i][j];
        }
        v.push_back(max);
    }
    return v;
}
// копия матрицы
Matrix copy(const Matrix& m)
{
    Matrix copymatr = newMatrix(m.n, m.m);
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.m; ++j)
            copymatr.matrix[i][j] = m.matrix[i][j];
    return copymatr;
}
// транспонирование матрицы 
void transpose(const Matrix& m)
{
    for (int i = 0; i < m.n; ++i)
        for (int j = i + 1; j < m.m; ++j)
            std::swap(m.matrix[i][j], m.matrix[j][i]);
}
// перемножение матриц
Matrix operator*(const Matrix& m, const Matrix& m1)
{
    Matrix pr = newMatrix(m.n, m1.m);
    for (int i = 0; i < m.n; i++)
        for (int j = 0; j < m1.m; j++)
            for (int k = 0; k < m1.n; k++)
                pr.matrix[i][j] += m.matrix[i][k] * m1.matrix[k][j];
    return pr;
}
// умножение матрица на число 
Matrix operator*(const Matrix& m, float n)
{
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.n; ++j)        
            m.matrix[i][j] *= n;
    return m;
}
// сложение матриц
Matrix operator+(const Matrix& m, const Matrix& m1)
{
    Matrix sum = newMatrix(m.n, m1.m);
    for (int i = 0; i < m.n; i++)
        for (int j = 0; j < m1.m; j++)         
                sum.matrix[i][j] = m.matrix[i][j] + m1.matrix[i][j];
    return sum;
}
// сравнение матриц
bool operator==(const Matrix& m, const Matrix& m1)
{
    bool result = true;
    if ((m.n != m1.n) && (m.m != m1.m))
    {
        result = false;
        return result;
    }
    else
    {
        for (int i = 0; i < m.n; ++i)
        {
            for (int j = 0; j < m.m; ++j)
            {
                if (m.matrix[i][j] == m1.matrix[i][j])
          
                    result = true;
                else
                {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
}
// заполнение улиткой 
void snail(Matrix& m)
{
    int i = 0;
    int k = 0;
    int p = 1;
    while (i < m.n * m.m) /*Цикл по номеру витка*/
    {
        k++;
        for (int j = k - 1; j < m.m - k + 1; j++)
        {
            m.matrix[k - 1][j] = p++;
            i++;
        }   /*Определение значений верхнего гор столбца*/

        for (int j = k; j < m.n - k + 1; j++)
        {
            m.matrix[j][m.m - k] = p++;
            i++;
        }   /* --//-- По правому вертикальному столбцу*/

        for (int j = m.m - k - 1; j >= k - 1; j--)
        {
            m.matrix[m.n - k][j] = p++;
            i++;
        }   /* --//-- по нижнему горизонтальному столбцу*/

        for (int j = m.n - k - 1; j >= k; j--)
        {
            m.matrix[j][k - 1] = p++;
            i++;
        }   /* --//-- по левому вертикальному столбцу*/
    }
}
// массив строк в одну строку
std::string join(const std::vector<std::string>& vector, const std::string& sep)
{
    std::string strok;
    for (const std::string& str : vector)
    {
        strok = str + sep;
    }
    return strok;
}


// Односвязный список 
struct ForwardListNode 
{
    int data;
    ForwardListNode * next; 
};
void insertAfter(ForwardListNode* node, int value)
{
    ForwardListNode *newNode = new ForwardListNode;    
    newNode->data = value;
    newNode->next = node->next;
    node->next = newNode;
}
void eraseAfter(ForwardListNode* node)
{
    node->next = node->next->next;
    delete node->next;
}
size_t size(const ForwardListNode * const head)
{
    size_t size = 0;
    ForwardListNode* tmp = head->next;
    while (tmp)
    {
        ++size;
        tmp = tmp->next;
    }
    return size;
}

// двусвязный список
struct ListNode 
{ 
    int data;
    ListNode * prev;
    ListNode * next; 
};
void insertAfter(ListNode* node, int value)
{
    ListNode *newNode = new ListNode;
    newNode->data = value;
    ListNode *tmp = new ListNode;
    tmp = node->next;
    tmp->prev = newNode;
    newNode->next = tmp; 
    newNode->prev = node;    
    node->next = newNode; 
    delete tmp;
}
void erase(ListNode* node)
{   
    node->prev = node->next->next;
    node->next->next = node->prev->prev;
    delete node; 
}
size_t size(const ListNode* const head)
{
    size_t size = 0;
    ListNode* tmp = head->next;
    while (tmp)
    {
        ++size;
        tmp = tmp->next;
    }
    return size;
}

int main()
{
    Matrix m = newMatrix(5, 5);
    for (int i = 0; i < m.n; ++i)
    {
        for (int j = 0; j < m.n; ++j)
        {
            m.matrix[i][j] = rand() % 20;
            std::cout << m.matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    //
    float maxim = max(m);
    std::cout << maxim << " max " << std::endl;
    //
    std::pair<int, int> resultmax = argmax(m);
    std::cout << resultmax.first << " " << resultmax.second << " index " << std::endl;
    //
    float minim = min(m);
    std::cout << minim << " min " << std::endl;
    //
    std::pair<int, int> resultmin = argmin(m);
    std::cout << resultmin.first << " " << resultmin.second << " index " << std::endl;
    //
    std::vector<float> v = maxStrok(m);
    for (const auto& e : v)
        std::cout << e << " ";
    std::cout << std::endl;
    //
    std::vector<float> vst = maxStolb(m);
    for (const auto& e : vst)
        std::cout << e << " ";
    std::cout << std::endl;
    //
    Matrix cop = copy(m);
    //
    Matrix matrixtmp = m * 10;

    Matrix sn = newMatrix(5, 5);
    snail(sn);
    for (int i = 0; i < sn.n; ++i)
    {
        for (int j = 0; j < sn.n; ++j)
        {           
            std::cout << sn.matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    

    system("pause");
    deleteMatrix(m);
    deleteMatrix(sn);
    return 0;
}

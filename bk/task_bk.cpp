/* 1
void main()
{  
    int x = 0;   
    int count = 0;
    int x1 = -99;
    int x2 = -99;
    while (x <= 0)
    {
        x = x1 + x2 + 120;        
        x2 = x1;
        x1 = x;
        ++count;
    }
    std::cout << count << std::endl;
    system("pause");
}

// 2
void main()
{    
    double x = 0;
    double y = 0;
    std::cin >> x >> y;
    if (((x+1) * (x+1) + y * y <= 1) && (y >= x + 1))
        std::cout << " Yes " << std::endl;
    else 
        std::cout << " No " << std::endl;   
    system("pause");
}

// 3
void main()
{
    double h = 0;
    double m = 0;    
    std::cin >> h >> m;
    double x = 0;
    int i = 0;
    if (h > m)
        std::cout << " Error! " << std::endl;
    if (m > 3.99)
        std::cout << " Ряд сходящийся " << std::endl;
    double n = 1;
    while (x <= m)
    {       
        x = ((2 * n - 1) * 2) / n;
        ++n;
        std::cout << " x - " << x << std::endl;
        if ((x >= h && x <= m))
            ++i;   
    } 
    std::cout << " i - " << i << std::endl;
    system("pause");
}

// 4
void main()
{
    double x = 0;
    double y = 0;
    std::cin >> x >> y;
    if (((x + 1) * (x + 1) + y * y <= 1) && (y >= (x + 1) * (x + 1)))
        std::cout << " Yes " << std::endl;
    else
        std::cout << " No " << std::endl;
    system("pause");
}

// 5
int main()
{
    int a = 0;
    int fa = 0;
    std::cin >> a;
    if ((a >= 0 && a <= 2))
        fa = a * a * a - 5;
    else if (a < 0)
    {
        do
        {
            a += 2;
        } while ((a >= 0 && a <= 2));
        fa = a * a * a - 5;
    }
    else if (a > 2)
    {
        do
        {
            a -= 2;
        } while ((a >= 0 && a <= 2));
        fa = a * a * a - 5;
    }
    std::cout << fa << std::endl;
    system("pause");
    return 0;
}
// 6
void main()
{
    double x = 0;
    double sum = 0;
    double tmpsum = 0;
    std::cin >> x;
    double e = 1e-4;
    int fact = 1;
    int k = 1;
    int zn = 1;
    double tmpx = x;
    do
    {
        tmpsum = tmpx / fact;
        sum += tmpsum * zn;
        tmpx = tmpx * x * x;
        k += 2;
        fact = fact * k * (k - 1);
        zn = -1;
    } while (tmpsum >= e);
    std::cout << sum << std::endl;
    system("pause");
}

// 7
void main()
{
    double x = 0;
    double y = 0;
    double fXY = 0;
    std::cin >> x >> y;
    if (x < y)
        fXY = x - 2 * y + x * y;
    else if (x == y)
        fXY = sin(x) * x;
    else if (x > y)
        fXY = y - 2 * x + 1;
    std::cout << fXY << std::endl;
    system("pause");
}

// 8 
void main()
{
    double x = 0;
    double y = 0;
    std::cin >> x >> y;
    if (y >= 0 && (x / 2 + 1 <= y || x / 2 <= y))
        std::cout << " Yes " << std::endl;
    else
        std::cout << " No " << std::endl;
    system("pause");
}

// 9
void main()
{
    double x = 0;   
    double fX = 0;
    std::cin >> x;
    if (x < 0)
        x = 0;
    else if ((x >= 0) && (x < 1.5))
        fX = pow((sin(x) + cos(x)), 2);
    else if (x >= 1.5)
        fX = sin(x) - sqrt(x) + cos(M_PI * pow(x, 2));
    std::cout << fX << std::endl;
    system("pause");
}

// 10
void main()
{
    double x = 0;
    double y = 0;
    std::cin >> x >> y;
    if (((x + 1) * (x + 1) + y * y <= 1) && (y <= -(x + 1) * (x + 1) + 1))
        std::cout << " Yes " << std::endl;
    else
        std::cout << " No " << std::endl;
    system("pause");
}

// 11
int sumMatr(int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];
    return sum;
}

int main()
{
    int n = 0;
    int m = 0;
    int sum = 0;
    std::cin >> n >> m;
    int ** matrix = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
        memset(matrix[i], 0, m * sizeof(matrix[0]));
    }   
    for (int i = 0; i < n; ++i)
    {      
        for (int j = 0; j < m; ++j) 
        {          
            matrix[i][j] = i + rand() % (j - i + 1);          
            std::cout << matrix[i][j] << "\t";
        }
        sum = sumMatr(matrix[i], n);
        std::cout << "sum = " << sum << std::endl;       
    }
  
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
    system("pause");
    return 0;
}

// 12
void main()
{
    int k = 0;
    std::cin >> k;
    int f = 0;
    int sum = 0;
    int f1 = 1;
    int f2 = 1;
    int i = 2;
    while (i <= k)
    {
        f = f1 + f2;
        f2 = f1;
        f1 = f;
        sum += f;
        ++i;
    }
    std::cout << sum << std::endl;
    system("pause");
}

// 13
void main()
{
    double e = 1e-4;
    double s = 0;
    double sum = 0;
    int k = 1;
    do
    {       
        s = (pow(-1, (k - 1))) / k;
        sum += s;
        ++k;
        std::cout << sum << std::endl;
    } while (s >= e);
    std::cout << sum << std::endl;
    system("pause");
}

// 14
void main()
{
    int a = 0;
    std::cin >> a;
    int f = 0;
    int count = 0;
    int f1 = 1;
    int f2 = 1;
    while (f <= a)
    {
        f = f1 + f2;
        f2 = f1;
        f1 = f;
        ++count;
    }
    std::cout << count << std::endl;
    system("pause");
}

// 15
void main()
{
    double R = 1e-4;
    double s = 0;
    double sum = 0;
    int k = 1;
    do
    {
        s = 1 / abs(k * (k + 1));
        sum += s;
        ++k;
    } while (s >= R);
    std::cout << s << std::endl;
    system("pause");
}

// 16
void main()
{
    int n = 0;
    std::cin >> n;
    int *a = new int[n];  
    for (int i = 0; i < n; ++i)
    {
        a[i] = 10 - rand() % 25;
        std::cout << a[i] << " ";      
    } 
    std::cout << std::endl;
    int min = a[0] + a[1];
    for (int i = 0; i < n; i += 2)
        if (min > a[i] + a[i + 1])
            min = a[i] + a[i + 1];
    std::cout << min << std::endl;    
    delete[] a;
    system("pause");
}

// 17
void main()
{
    int i = 0;
    int n = 0;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand() % 100 + 1;
        if (a[i] % 2 == 0)
            ++i;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    std::cout << i << std::endl;
    delete[] a;
    system("pause");
}
// 18
bool asc(const int a, const int b) 
{
    return a < b;
}
void main()
{    
    int n = 0;
    std::cin >> n;
    int *a = new int[n];
    bool flag = false;
    for (int i = 0; i < n; ++i)    
        a[i] = rand() % 99;    
    std::sort(a, a + n, asc);
    for (int i = 0; i < n; ++i)       
        std::cout << a[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < n; ++i)
    {       
        if ((a[i] % 3 == 0) && (a[i] % 5 != 0))
        {
            std::cout << a[i] << " Kratno 3, ne kratno 5 " << std::endl;
            flag = true;
        }
    }
    if (flag = false)  
        std::cout << " chisel net " << std::endl;
    delete[] a;
    system("pause");
}

// 19
bool asc(const int a, const int b)
{
    return a < b;
}
void main()
{
    int n = 0;
    std::cin >> n;
    int *a = new int[n];
    bool flag = false;
    for (int i = 0; i < n; ++i)
        a[i] = -50 + rand() % 99;
    std::sort(a, a + n, asc);
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] < 0) && (a[i] % 2 != 0))
        {
            std::cout << a[i] << " Ne chetno, otr " << std::endl;
            flag = true;
        }
    }
    if (flag = false)  
        std::cout << " chisel net " << std::endl;
    delete[] a;
    system("pause");
}

// 20
bool asc(const int a, const int b)
{
    return a < b;
}
void main()
{
    int n = 0;
    std::cin >> n;
    int *a = new int[n];
    bool flag = false;
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 200;
    std::sort(a, a + n, asc);
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] % 9 == 1) || (a[i] % 9 == 2) || (a[i] % 9 == 5))
        {
            std::cout << a[i] << " nuzniu osatok " << std::endl;
            flag = true;
        }
    }
    if (flag = false)  
        std::cout << " chisel net " << std::endl;
    delete[] a;
    system("pause");
}

// 21
int maxElem(int *a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; ++i)
        if (max < a[i])
            max = a[i];
    return max;
}
int main()
{
    int n = 0;
    int m = 0;
    int sum = 0;
    std::cin >> n >> m;
    int ** matrix = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
        memset(matrix[i], 0, m * sizeof(matrix[0]));
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = -10 + rand() % 20;
            std::cout << matrix[i][j] << "\t";
        }
        sum = maxElem(matrix[i], n);
        std::cout << "max = " << sum << std::endl;
    }

    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
    system("pause");
    return 0;
}

// 22
int minElem(int *a, int n)
{
    int min = a[0];
    for (int i = 0; i < n; ++i)
        if (min > a[i])
            min = a[i];
    return min;
}
int main()
{
    int n = 0;
    int m = 0;
    int sum = 0;
    std::cin >> n >> m;
    int ** matrix = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
        memset(matrix[i], 0, m * sizeof(matrix[0]));
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = -10 + rand() % 20;
            std::cout << matrix[i][j] << "\t";
        }
        sum = minElem(matrix[i], n);
        std::cout << "min = " << sum << std::endl;
    }
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
    system("pause");
    return 0;
}

// 23
bool asc(const int a, const int b)
{
    return a < b;
}
void main()
{
    int n = 0;
    std::cin >> n;
    int *a = new int[n];
    bool flag = false;
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 155;
    std::sort(a, a + n, asc);
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] % 7 == 1) || (a[i] % 7 == 2) || (a[i] % 7 == 5))
        {
            sum += a[i];            
            flag = true;
        }
    }
    if (flag = true)
        std::cout << " Summa " << sum << std::endl;
    else
        std::cout << " chisel net " << std::endl;
    delete[] a;
    system("pause");
}

//24
void main()
{
    
    int n = 0;
    std::cin >> n;
    int N = 0;
    int sum = 0;
    bool flag = false;
    for (int i = 1; i <= n; ++i)
    {
        N = pow(i, 3) - 3 * i * pow(n, 2) + n;
        if ((N % 3 == 0) && (N % 2 != 0))
        {
            sum += N;
            flag = true;
        }
    }
    if (flag = true)
        std::cout << sum << std::endl;
    else 
        std::cout << " chisel net " << std::endl;
    std::cout << std::endl;
    system("pause");
}

// 25
float arifm(float *a, int n)
{
    float sum = 0;    
    for (int i = 0; i < n; ++i)
        sum += a[i];   
    return sum / n;
}

int main()
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    float ** matrix = new float *[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new float[m];        
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = -10 + rand() % 20;
            std::cout << matrix[i][j] << "\t";
        }
        float average = arifm(matrix[i], n);
        std::cout << "arifm = " << average << std::endl;
    }
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
    system("pause");
    return 0;
}
*/

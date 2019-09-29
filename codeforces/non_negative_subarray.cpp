#include <iostream>
#include <vector>

//std::vector<int> V{ -54961, 3510, -50805, -82137, -39096, -47421 };
//std::vector<int> V{ -1, -1, -1, -1 };
//std::vector<int> V{137806862, -982906996, -511702305, -1937477084};
std::vector<int> V{0, 0, -1, 0};

typedef long long bigtype;
std::vector<int> maxset(const std::vector<int>& A)
{
    if (A.empty()) { return std::vector<int>(); }
    
    size_t start{A[0] < 0 ? 1 : 0};
    bigtype sum{A[0] < 0 ? 0 : A[0]};

    size_t bestStart{start};
    size_t bestEnd{0};
    bigtype bestSum{sum};
    
    for(size_t i = 1; i < A.size(); ++i)
    {
        const int Value{A[i]};
        std::cout << "Value = " << Value << std::endl;
        if (Value < 0)
        {
            std::cout << "Negative." << std::endl;
            sum = 0;
        }
        else
        {
            std::cout << "Positive." << std::endl;
            if (A[i - 1] < 0)
            {
                start = i;
                std::cout << A[i - 1] << " is prev value. "
                          << "Start is " << i << std::endl;
            }
            
            sum += Value;
            std::cout << "New sum is " << sum << " and bestSum is " 
                      << bestSum << std::endl;
            
            const int ThisLen{i - start};
            const int BestLen{bestEnd - bestStart};
            if (sum > bestSum || 
                    sum == bestSum && 
                        (BestLen < ThisLen))
            {
                std::cout << bestSum << " is new best sum!" << std::endl;
                bestStart = start;
                bestEnd = i;
                bestSum = sum;
                std::cout << "bestStart = " << bestStart << std::endl;
                std::cout << "bestEnd = " << bestEnd << std::endl;
            }
        }
    }
    
    if (bestSum < 0) { return std::vector<int>(); }
    std::cout << "bestStart = " << bestStart << std::endl;
    std::cout << "bestEnd = " << bestEnd << std::endl;
    return std::vector<int>(A.begin() + bestStart, A.begin() + bestEnd + 1); 
}

int main()
{
	const auto r = maxset(V);

	for (const auto& value : r)
	{
		std::cout << value << " ";
	}
}

#include <algorithm>
#include <iostream>
#include <vector>

/*


*/

int main() {

    std::vector<int> v = {-5, -10, 20, 25, -30, 40, 0, -1, 60, 7};

    // almeno un valore non negativo
    auto nonneg = std::find_if(v.begin(), v.end(), [](int x){
        return x >= 0;
    });

    if (nonneg != v.end()) {
        std::cout << "esiste almeno un valore non negativo: " << *nonneg << std::endl;
    } else {
        std::cout << "non esistono valori non negativi" << std::endl;
    }

    // primo valore > 30
    auto grande = std::find_if(v.begin(), v.end(), [](int x){
        return x > 30;
    });

    if (grande != v.end()) {
        std::cout << "primo valore > 30: " << *grande << std::endl;
    } else {
        std::cout << "nessun valore > 30" << std::endl;
    }

    // rimuovi i negativi (C++17)
    v.erase(
        std::remove_if(v.begin(), v.end(), [](int x){
            return x < 0;
        }),
        v.end()
    );

    // ordina crescente
    std::sort(v.begin(), v.end());

    // stampa finale
    std::cout << "vettore finale: ";
    for (auto x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}

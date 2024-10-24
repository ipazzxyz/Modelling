# Классы

## Основной класс. class System

В нем происходит и хранится вся логика программы. Создаем один экземпляр и работаем с ним.

### Инициализация

```C++
System::System(double разброс,  double налог, double изначальная капитализация, int кол-во месяцев (M));
```

### Разброс

считается в классе Market по формуле
$S_{ i } = S_{ i - 1 } * ( 1 + 2 * R * X - X)$, где S - стоимость, R случайное число $( 0 \leq R \leq 1 )$, X - разброс. Тогда $S_{i} \in [S_{i - 1} * (1 - X), S_{i - 1} * (1 + X)]$.

### Переход на следующий шаг

```C++
void System::Iterate();
```

### Покупка/продажа

```C++
void BuyBond(Currency currency, int amount);
void BuyStock(Currency currency, int amount);
void BuyAsset(Currency currency, double amount);
void SellStock(Currency currency, int amount);
void SellAsset(Currency currency, double amount);
```
### Доступ к другим классам

Осуществляется через геттеры.

```C++
const std::map<Currency, Bond>& GetAllBonds() const;
const std::map<Currency, Stock>& GetAllStocks() const;
const std::map<Currency, Asset>& GetAllAssets() const;
const std::vector<UniqueBond>& GetAllYourBonds() const;
const std::vector<Depositor>& GetAllYourDepositors() const;
double GetConventionalUnits() const;
double GetCapitalization() const;
int GetStockAmount(Currency currency) const;
int GetAssetAmount(Currency currency) const;
int GetAmountShare(Currency currency) const;
```

## Класс рынка. class Market

Хранит цены акций, ценных бумаг.

### Получение цены покупки / продажи

```C++
double Market::GetBuyPrice(Currency название);
double Market::GetSellPrice(Currency название);
```

### Получение процента по депозиту в банке

```C++
double GetDepositPercent();
```
### Ошибки

```C++
class DoesNotExistBond: public std::exception {
public:
    const char *what() const noexcept;
};
class DoesNotExistStock: public std::exception {
public:
    const char *what() const noexcept;
};
class DoesNotExistAsset: public std::exception {
public:
    const char *what() const noexcept;
};
```

### Получение map

```C++
const std::map<Currency, Bond>& GetAllBonds() const;
const std::map<Currency, Stock>& GetAllStocks() const;
const std::map<Currency, Asset>& GetAllAssets() const;
```

### Получение количество дивидендов за единицу валюты 

```C++
double GetDividends(Currency название);
```

## Класс фонда. class Fund

Хранит то, чем обладаем в данный момент.

### Получение кол-ва свободной валюты

```C++
double Fund::GetConventionalUnits();
```

### Получение кол-ва валюты

```C++
double Fund::GetAmount(Currency название);
```

### Получение капитализации

```C++
double Fund::GetCapitalization(Market &market);
```
### Создание депозита

```C++
void MakeDeposit(const Market& market, double deposit, int term, int month);
```
### Получение списка вкладчиков

```C++
vector<Depositor> &GetDepositors();
```

### Покупка / продажа

```C++
void BuyBond(const Market& market, Currency currency, int amount);
void BuyStock(const Market& market, Currency currency, int amount);
void BuyAsset(const Market& market, Currency currency, double amount);
void SellStock(const Market& market, Currency currency, int amount);
void SellAsset(const Market& market, Currency currency, double amount);
```


# Логика

## ConventionalUnits

У нас есть свободная стабильная валюта (ConventionalUnits), которая никогда не меняет свой курс. Она хранится отдельно. При продаже какой либо валюты, средства конвертируются в эту стабильную валюту по нынешнему курсу. При покупке валюты, средства вычитаются из стабильной валюты по нынешнему курсу.

## Остальные валюты

Наименования остальных валют лежат в enum class Currency, а логика в Asset (или наследованных от Asset классах, в зависимости от типа валюты). Работа с ними происходит через интерфейсы классов, описанных выше.

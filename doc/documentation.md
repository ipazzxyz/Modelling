# Классы

## Основной класс. class System

В нем происходит и хранится вся логика программы. Создаем один экземпляр и работаем с ним.

### Инициализация

```C++
System::System(int кол-во месяцев (M), double изначальная капитализация, double налог, double разброс);
```

### Разброс

считается в классе Market по формуле
$S_{ i } = S_{ i - 1 } * ( 1 + 2 * R * X - X)$, где S - стоимость, R случайное число $( 0 \leq R \leq 1 )$, X - разброс. Тогда $S_{i} \in [S_{i - 1} * (1 - X), S_{i - 1} * (1 + X)]$.

### Переход на следующий шаг

```C++
void System::Iterate();
```

### Доступ к другим классам

Осуществляется через геттеры.

```C++
Market System::GetMarket();
Fund System::GetFund();
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

### Получение map

```C++
double GetDividends(Currency название);
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

### Получение списка вкладчиков

```C++
vector<Depositor> &GetALlDepositors();
```

### Покупка / продажа

```C++
void Buy(const Market &market, Currency currency, int amount);  
void Sell(const Market &market, Currency currency, int amount);
```


# Логика

## ConventionalUnits

У нас есть свободная стабильная валюта (ConventionalUnits), которая никогда не меняет свой курс. Она хранится отдельно. При продаже какой либо валюты, средства конвертируются в эту стабильную валюту по нынешнему курсу. При покупке валюты, средства вычитаются из стабильной валюты по нынешнему курсу.

## Остальные валюты

Наименования остальных валют лежат в enum class Currency, а логика в Asset. Работа с ними происходит через интерфейсы классов, описанных выше.

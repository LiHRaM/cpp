// Daily stock price
struct StockPrice
{
    unsigned day;     // day number
    unsigned price;   // price in USD cents
};

// Temperature measurement
class TempMeasure
{
   public:
    TempMeasure () : m{0.0} {}
    TempMeasure (double _m) : m{_m} {}

    operator double() const { return m; }

   private:
    double m;
};
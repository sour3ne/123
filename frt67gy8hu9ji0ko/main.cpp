
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int sum_period(int arr[], int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian"); //по какойто не известной мне причине на моем ноуте в xcode странно отображается русский алфавит. нашел вот такоц способ. к следующей практике решу эту проблему

    int load[24];
    int i;

    cout << "Введите нагрузку сети для каждого часа в сутках " <<endl;

    for (i = 0; i < 24; i++) {
        cout << "Час " << i << ": ";
        cin >> load[i];
    }

    int sum_night = sum_period(load, 0, 5);
    int sum_morning = sum_period(load,6, 11);
    int sum_day = sum_period(load, 12, 17);
    int sum_evening = sum_period(load, 18, 23);

    int max_load = sum_night;
    string max_time = "Ночь";

    if (sum_morning > max_load) {
        max_load = sum_morning;
        max_time = "Утро";
    }
    if (sum_day > max_load) {
        max_load = sum_day;
        max_time = "День";
    }
    if (sum_evening > max_load) {
        max_load = sum_evening;
        max_time = "Вечер";
    }

    cout << endl;
    cout << "Сумма за ночь: " << sum_night << endl;
    cout << "Сумма за утро: " << sum_morning << endl;
    cout << "Сумма за день: " << sum_day << endl;
    cout << "Сумма за вечер: " << sum_evening << endl;
    cout << endl;
    cout << "Самое загруженное время суток: " << max_time << endl;

    return 0;
}




#include <iostream>
#include <string>
#include <locale>

using namespace std;

bool is_link(const string& t, int p) {
    if (p + 7 <= t.length()) {
        string part = t.substr(p, 7);
        if (part == "http://") return true;
    }
    if (p + 8 <= t.length()) {
        string part = t.substr(p, 8);
        if (part == "https://") return true;
    }
    return false;
}

string get_link(const string& t, int p) {
    string link = "";
    int i = p;
    while (i < t.length()) {
        char c = t[i];
        if (c == ' ' || c == '"' || c == '\'' || c == '>' || c == '\n' || c == '\t') {
            break;
        }
        link += c;
        i++;
    }
    return link;
}

void find_links(const string& text) {
    int count = 0;
    for (int i = 0; i < text.length(); i++) {
        if (is_link(text, i)) {
            string link = get_link(text, i);
            count++;
            cout << "Link " << count << ": " << link << endl;
        }
    }
    cout << endl;
    cout << "Total: " << count << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    string html = R"(
    <html>
    <body>
    <p>Site: <a href="https://www.susu.ru/ru">SUSU</a></p>
    <p>Search: <a href="https://ya.ru/?npr=1">Yandex</a></p>
    <p>Archive: <a href="http://web-archive.com">Web Archive</a></p>
    <p>More: https://google.com and http://example.org/page</p>
    </body>
    </html>
    )";
    
    cout << "Searching links..." << endl;
    find_links(html);
    
    return 0;
}


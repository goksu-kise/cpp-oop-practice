# cpp-oop-practice

C++ ile nesne yönelimli programlama (OOP) alıştırmaları.

## hastane_sistemi.cpp

Hastane personeli ve hastaları modelleyen bir örnek. Şunları kullanıyor:

- Soyut taban sınıf (`Kisi`) ve türeyen sınıflar (`Doktor`, `Hemsire`, `Hasta`)
- Sanal fonksiyonlar ve polimorfizm (`vector<Kisi*>`)
- Sanal yıkıcı ve `delete` ile bellek temizliği
- `try/catch` ile hata yönetimi

Program ne yapıyor:

1. Tüm kişilerin bilgisini yazdırır, en yüksek maaşlı kişiyi gösterir.
2. Girilen kimlik numarasına sahip kişiyi bulur.
3. Girilen maaştan düşük maaşı olan kişileri listeler (negatif girilirse hata verir).

### Derleme ve çalıştırma

```
g++ -std=c++17 -Wall -Wextra hastane_sistemi.cpp -o hastane
./hastane
```

### Bilinen eksikler

- `Hasta` sınıfı maaş karşılaştırmalarına dahil oluyor (tedavi ücreti maaş gibi kullanılıyor).
- Sayı yerine harf girilirse girdi doğrulaması yok.

# Push_Swap

## 1. Proje Açıklaması
**push_swap**, belirli kurallar çerçevesinde verilen bir dizi tamsayıyı sıralamak için kullanılan bir algoritma uygulamasıdır. Bu proje, sınırlı sayıda komut kullanarak **en az adımda** sıralama yapmayı amaçlayan verimli bir sıralama algoritması geliştirmeyi hedefler.

## 2. Kurallar ve Gereksinimler
- Program, iki stack (**A** ve **B**) kullanarak çalışır.
- Başlangıçta **stack A**, sıralanması gereken tamsayıları içerir ve **stack B** boştur.
- Sadece belirlenen komutlar kullanılarak elemanlar taşınabilir veya sıralanabilir.
- Programın çıktısı, tamsayıları artan sıraya göre sıralayan en optimize edilmiş komut listesidir.

## 3. Kullanılabilir Komutlar

| Komut | Açıklama |
|--------|-----------|
| `sa` | Stack A'daki ilk iki elemanı değiştirir |
| `pa` | Stack B'deki ilk elemanı Stack A'ya taşır |
| `pb` | Stack A'daki ilk elemanı Stack B'ye taşır |
| `ra` | Stack A'yı yukarı kaydırır (ilk eleman sona gider) |
| `rr` | `ra` ve `rb` komutlarını aynı anda uygular |
| `rra` | Stack A'yı aşağı kaydırır (son eleman başa gelir) |
| `rrr` | `rra` ve `rrb` komutlarını aynı anda uygular |

## 4. Kurulum ve Çalıştırma
1. **Depoyu klonlayın:**
   ```sh
   git clone https://github.com/kullaniciadi/push_swap.git
   cd push_swap
   ```
2. **Projeyi derleyin:**
   ```sh
   make
   ```
3. **Programı çalıştırın:**
   ```sh
   ./push_swap 4 67 3 87 23
   ```
4. **Sonuç:** Program, verilen sayıları sıralamak için gereken en optimize edilmiş komut listesini yazdırır.

## 5. Algoritma Mantığı
- **Küçük sayılar için özel durumlar**: 2-5 eleman için özel sıralama stratejileri uygulanır.
- **Bit Manipülasyonu ile Sıralama**: Büyük veri setleri için **Radix Sort** algoritması bit manipülasyonu ile optimize edilmiştir. 
  - İlk olarak, giriş değerleri sıralı bir şekilde indexlenir.
  - Indexlenen sayılar, en az bit kaydırma işlemi ile sıralanacak şekilde değerlendirilir.
  - **LSB (Least Significant Bit) bazlı sıralama** kullanılarak, en düşük bitlerden başlanarak sıralama yapılır.
- **Komut optimizasyonu**: Gereksiz hareketleri en aza indiren akıllı sıralama teknikleri uygulanır.

## 6. Hata Yönetimi
- **Geçersiz karakterler veya harfler içeren girişler** hata mesajı döndürmelidir.
- **Tekrarlayan sayılar girildiğinde** program hata vermelidir.
- **Tamsayı sınırlarını aşan değerler** kabul edilmemelidir.

## 7. Örnek Kullanım
### Girdi:
```sh
./push_swap 5 1 4 2 3
```
### Çıktı:
```
pb
pb
sa
pa
pa
```
(Bu, verilen sayıları sıralamak için kullanılan optimize edilmiş komut listesidir.)

## 9. Kaynaklar
- [42 School Subject PDF](https://github.com/42docs/push_swap)
- Algoritma optimizasyonu üzerine çeşitli kaynaklar ve makaleler.

## 10. Lisans
Bu proje **42 School** eğitim programı kapsamında geliştirilmiştir ve herhangi bir ticari kullanım amacı taşımamaktadır.


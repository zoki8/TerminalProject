# TerminalProject

Interpreter komandne linije (CLI) napisan u C++-u, rađen kao projektni zadatak iz Objektno orijentisanog programiranja 1 na ETF-u u Beogradu.

Interpreter učitava komandu po komandu sa konzole (ili iz batch fajla), izvršava je i ispisuje rezultat. Podržava redirekciju ulaza/izlaza i cevovode (pipe).

## Podržane komande

| Komanda | Opis |
|---|---|
| `echo [arg]` | prosleđuje ulaz na izlaz |
| `prompt "text"` | mijenja znak spremnosti (podrazumijevano `$`) |
| `time` | ispisuje trenutno vrijeme |
| `date` | ispisuje trenutni datum |
| `touch file` | pravi prazan fajl |
| `truncate file` | briše sadržaj fajla |
| `rm file` | briše fajl |
| `wc -w/-c [arg]` | broji riječi (`-w`) ili znakove (`-c`) |
| `tr [arg] -"what" ["with"]` | zamjenjuje (ili uklanja) niz znakova |
| `head -nN [arg]` | ispisuje prvih N linija |
| `batch file` | izvršava komande iz fajla |

## Mogućnosti

- Ulaz iz konzole, iz argumenta pod navodnicima ili iz fajla
- Redirekcija: `<` (ulaz), `>` (izlaz), `>>` (dodavanje na kraj fajla)
- Cevovodi: `time | tr -":" "." | wc -c > time.txt`
- Obrada grešaka (leksičke, sintaksne, semantičke, greške OS-a)

## Kompajliranje

    cd Mojprojekat
    g++ *.cpp -o cmi

## Pokretanje

    ./cmi

Primjer:

    $ wc -w "Lorem ipsum dolor sit amet"
    5
    $ echo "Hello" > out.txt
    

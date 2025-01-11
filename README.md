# Oicho-Kabu
 Projektni zadatak iz OOP-a
Pravila Oicho-Kabu-a:
Oicho-Kabu [おいちょかぶ] (dosl. "osam-devet") tradicionalna je kockarska igra u kojoj se grupa igrača natječe protiv bankara kako bi sastavili ruku čija je vrijednost što bliže devetki.

Jednostavna i široko popularna igra na mnogo načina podsjeća na Baccarat i Blackjack. Također ima snažne kulturne poveznice s kriminalnim podzemljem; Oicho-Kabu je nezaobilazan dio Yakuza kockarnica, a sama riječ ‘yakuza’ potječe iz terminologije ove igre.
Priprema

Priprema igre uključuje odabir dealer-a - 親 [おや, oya], dogovor o rasporedu sjedenja ostalih igrača i miješanje špila. Prije početka igre treba se dogovoriti o određenim osnovnim pravilima.

Osnovna pravila

Prije početka igre, grupa bi se trebala dogovoriti o sljedećem:

    Što se događa u slučaju izjednačenja između igrača i djelitelja. Postoje dvije opcije: rezultat je neriješen i ulog se vraća igraču ili djelitelj pobjeđuje.
    Maksimalni ukupni ulog. Ovo je ograničenje na iznos bodova koji se može uložiti po rundi – zbroj svih uloga svih igrača ne smije ga premašiti, a kad se dostigne, daljnji ulozi nisu dopušteni.

Za svrhe naše igre ako je rezultat između "dealer" i "player" neriješena to je "tie", a što se tiče uloga igramo s malo promijenjenim pravilima da se igra u najviše pobjeda. 

Tijekom runde svaki igrač pokušava formirati ruku čija ukupna vrijednost što bliže odgovara devetki. Ukupni zbrojevi iznad 9 "okreću se" odbacivanjem znamenke desetica. Tako je 10 ekvivalentno 0, 11 ekvivalentno 1 i tako dalje, slično kao u Baccaratu. Slično drugim bankarskim igrama, igrači se ne natječu jedni protiv drugih, već samo nastoje pobijediti djelitelja. Četiri karte se dijele licem prema gore u red na stolu. To je poznato kao prvo polje – svaka od te četiri karte  može biti temelj za ruku. 

igrači po redu odabiru svoju prvu kartu, zatim "dealer" dobija svoju prvu kartu te se igračima nakon toga dijeli druga karta na onu "ruku" koju su prvu odabrali. S obzirom na ograničenja projektnog zadatka svim igračima su sve "ruke" vidljive dok igra traje.

Kada svi igrači dobiju svoju drugu kartu oni mogu odlučiti žele li uzeti treću kartu s time da moraju paziti na tri pravila:
Ako je ukupna vrijednost ruke 3 ili manja, treća karta mora se uzeti.
Ako je ukupna vrijednost ruke 7 ili veća, treća karta se ne može uzeti.
Ako je vrijednost ruke između 3 i 7 igrači mogu odlučiti žele li ili ne žele uzeti dodatnu kartu.


Zatim kada su svi igrači dobili svoje karte "dealer" uzima svoju drugu kartu te po istim pravilima kao što izabiru igrači "dealer" izabire svoju treću kartu.



Kraj runde:
Ako igrač ima veću vrijednost ruke od "dealer"-a igrač pobjeđuje
Ako "dealer" ima veću vrijednost ruke od igrača "dealer" pobjeđuje
Ako su igrač i "dealer" neriješeni onda nitko ne dobija pobijedu

Tri posebna pravila

    Tri iste karte [嵐 - あらし, arashi]: Ako su karte u prvom, drugom i trećem polju jednake vrijednosti,  automatska pobjeda protiv svih ruku na stolu. 
    4 i 1 [四一 - しっぴん, shippin]: Ako je prva karta  4, a druga 1,  automatska pobjeda protiv svih ruku na stolu.

     9 i 1 [九一 - くっぴん, kuppin]: Ako je prva karta  9, a druga 1,   automatska pobjeda protiv svih ruku na stolu.
Ako "dealer" i igrač imaju jednu od tri posebne ruke "dealer" automatski pobjeđuje tu rundu protiv tog igrača.

Nakon što se izračunaju sve vrijednosti ruke i dodijele se sve pobjede svaki igrač i "dealer" rotiraju svoja mjesta.


Igra traje 4 runde (dok se svi ne izrotiraju na njihovo originalno mjesto).










Upute:
[Oicho-Kabu](https://github.com/TSegvic/Oicho-Kabu/releases/tag/program)
Pritisnite ne [link](https://github.com/TSegvic/Oicho-Kabu/releases/tag/program) i downloadajte .exe file
Nakon što upalite file upišite sve što se traži od vas na ekranu tj.:
Je li dealer ljudski igrač (odgovarate s y za yes ili n za no)
Ako je odgovor 'y' unesite mu ime
Koliko ljudskih igrača igra kao "player"
Unesite njihova imena (ako ih ima)
Za svaku rundu:
Za igrača kojeg vi igrate unesite broj koji odgovara karti koju želite uzeti
Ako možete odabirati još karata pritisnite 'y' za yes i 'n' za no
Zatim dealer odabire svoje karte (ako može)
Kada izračuna pobjede pritisnite Enter za nastavak na iduću rundu 

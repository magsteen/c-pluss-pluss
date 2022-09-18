## Oppgave 2

På første linje lager vi en char pointer som peker til nullptr addressen. (Kan si at den peker til verdien null)

strcpy() sin funksjon er å kopiere data fra en kilde char pointer, til en destinasjons char pointer. I dette tilfellet prøver vi å kopiere over dataen “Dette er en tekst” til char pointeren line. 

Dvs vi prøver å sette dataen som nullpointer addressen peker til, til “Dette er en tekst”. Vi har ikke lov til å endre på dataen i nullptr addressen, samt at det ikke er allokert nødvendig minne for å peke til dataen. 

Dette fører til en “Segmentation fault” og avslutter programmet.

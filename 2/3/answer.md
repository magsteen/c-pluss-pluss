## Oppgave 3

cin >> text hindrer ikke bruker fra å putte inn mer data enn tabellen text har satt av. Ved å putte inn for mye data (mer enn 4 karakterer i dette tilfellet pga avsluttende nullbyte) vil et linux OS se på dette som et forsøk for “stack smashing” og terminerer programmet. 

Hvis loopen ikke finner en ‘e’ i text tabellen innen den når enden av tabellen, vil den prøve å lese og skrive over data utenfor tabellen. Dette tolkes som “stack smashing” av et linux OS og fører til at programmet termineres. 

En annen ting som kan være feil her, avhengig av hva hensikten med programmet er, er at alle karakterer i input teksten til brukeren endres til ‘e’ fram til første ‘e’ karakter blir funnet.

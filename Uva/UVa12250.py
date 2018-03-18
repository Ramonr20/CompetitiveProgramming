saludos = {
    "HELLO":"ENGLISH",
    "HOLA":"SPANISH",
    "HALLO":"GERMAN",
    "BONJOUR":"FRENCH",
    "CIAO":"ITALIAN",
    "ZDRAVSTVUJTE":"RUSSIAN"
}


saludo = "1"
i = 1

while(saludo):
    saludo = str(input())
    if saludo == '#':
        break
    if saludo in saludos:
        print("Case {}: {}".format(i,saludos[saludo]))
    else:
        print("Case {}: UNKNOWN".format(i))
    i += 1

    
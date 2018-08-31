class BigString {
    public static void main(String[] args) {
        int cantidad = 0;
        int pos = 0;
        long numero = Long.parseLong(args[0]);
        StringBuilder BigString = new StringBuilder();
        char[] letras = new char[4];
        letras[3] = ' ';
        int rango = (90 - 65) + 1;
        long startTime = System.nanoTime();

        for (long i = 0; i < numero ; i++) {
            letras[0] = (char)((Math.random()*rango) + 65);
            letras[1] = (char)((Math.random()*rango)+ 65);
            letras[2] = (char)((Math.random()*rango)+ 65);
            BigString.append(letras);
        }

        while ((pos = BigString.indexOf("IPN", pos)) != -1){
            cantidad++;
            pos += 4;
        }

        System.out.println("Numero de IPN: " + cantidad);
    }
}
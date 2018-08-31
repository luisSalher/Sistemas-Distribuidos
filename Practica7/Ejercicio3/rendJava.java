public class rendJava {
    public static void main(String[] args){
    int Max=20000000;
    double i=0;
    double seno=0,coseno=0,tangente=0,logaritmo=0,raizCuad=0;
    while(i<Max){
        seno += Math.sin(i);
        coseno += Math.cos(i);
        tangente += Math.tan(i);
        logaritmo += Math.log10(i);
        raizCuad += Math.sqrt(i);
        i++;
    }
    //System.out.println("Fin ");
}}

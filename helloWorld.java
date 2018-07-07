public class HelloWorld {
    public String makeSentence(String[] words) {
         StringBuffer sentence = new StringBuffer();
         for (String w : words) sentence.append(w);
         return sentence.toString();
        }
        
    public static void main(String[] args) {
        // Prints "Hello, World" to the terminal window.
        System.out.println("Hello, World");
    }

}
 
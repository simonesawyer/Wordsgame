import java.util.Random;
import java.util.Scanner; 
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;
public class wordGame {
    final static int ASCIIOFFSET = 97;
    private static Set<String> wordsSet;
    private static Set<String> badList;
    public static void main(String[]args) {
        Random rand = new Random();
        String guessingLetters = "";
        Scanner myObj = new Scanner(System.in);
        String guess = "";
        try {
            Dictionary();
        }catch(Exception e) {
            //  Block of code to handle errors
        }
        System.out.println("This is a three letter word game. With the provided letters you have to \nguess a real word. In order to quite the game type \'q\'. To reroll \nanother choice type 'r'. This program only takes lowercase letters.\n");
        boolean iscorrect = false;
        while(!guess.equals("q")){
            guessingLetters = randomThreeLetters(rand);
            System.out.println("Can you think of a word that contains "+guessingLetters+"?");
            while(!iscorrect){
                guess = myObj.nextLine();
                if(guess.equals("q")){
                  break; 
                }
                if(guess.equals("r")){
                    iscorrect = true;
                    continue; 
                  }
                String temp = guess;
                if(!temp.contains(guessingLetters.substring(0,1))){
                    System.out.println("Wrong guess "+ guess + " does not contain "+ guessingLetters.substring(0,1));
                    continue;
                }
                temp = temp.replaceFirst(guessingLetters.substring(0,1), "");
                if(!temp.contains(guessingLetters.substring(1,2))){
                    System.out.println("Wrong guess "+ guess + " does not contain "+ guessingLetters.substring(1,2));
                    continue;
                } 
                temp = temp.replaceFirst(guessingLetters.substring(1,2), "");
                if(!temp.contains(guessingLetters.substring(2))){
                    System.out.println("Wrong guess "+ guess + " does not contain "+ guessingLetters.substring(2));
                    continue;
                }
                
                if(!contains(guess)){
                    System.out.println("Wrong guess "+ guess + " is not a word. Try again");
                    continue;
                }
                iscorrect = true;
                System.out.println("You are correct!!");
            }
            iscorrect = false;
        }
        // Enter username and press Enter
                
    }
    public static String randomThreeLetters(Random rand){
        String guessingLetters = "";
        guessingLetters += (char)(rand.nextInt(26)+ ASCIIOFFSET);
        guessingLetters += (char)(rand.nextInt(26)+ ASCIIOFFSET);
        guessingLetters += (char)(rand.nextInt(26)+ ASCIIOFFSET);
        while(badList.contains(guessingLetters)){
            guessingLetters = "";
            guessingLetters += (char)(rand.nextInt(26)+ ASCIIOFFSET);
            guessingLetters += (char)(rand.nextInt(26)+ ASCIIOFFSET);
            guessingLetters += (char)(rand.nextInt(26)+ ASCIIOFFSET);
        }
       
        return guessingLetters;
    }

    public static boolean contains(String word)
    {
        return wordsSet.contains(word);
    }
    public static void Dictionary() throws IOException
    {
	      try (Stream<String> lines = Files.lines(Paths.get("words.txt"))) {
		    wordsSet = lines.collect(Collectors.toSet());
	      }
          try (Stream<String> lines = Files.lines(Paths.get("badCombos.txt"))) {
		    badList = lines.collect(Collectors.toSet());
	      }
    }


}

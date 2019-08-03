/**
 * Cracking the Coding Interview Problem 8.1
 * Designing the data structure for a generic deck of cards.
 *
 * FIRST we define a type 'Suit'.
 * THEN we define a class Card.
 * THEN we define a class Hand (representing one's hand of cards).
 */

// Defining a type 'Suit'.
 public enum Suit {
     // enum = a user-defined type
     Clubs(1), Diamonds(2), Spades(3), Hearts(4);
     private int value;
     // Setting the suit's value:
     private Suit(int v) { value = v; }
     public int getValue() { return value; }

     // Additional function:
     public static Suit getSuitFromValue(int value) {
         ...
     }
 }

 // Card = an abstract class because some methods do not make sense without
 // a game being played.
 public abstract class Card {
     // Whether or not card is available to be given out:
     private boolean available = true;

     protected int faceValue;
     protected Suit suit;

     public Card(int f, Suit s) {
         faceValue = f;
         suit = s;
     }

    // A Card's functions re: availability.
     public boolean isAvailable() { return available; }
     public void makeUnavailable() { available = false; }
     public void makeAvailable() { available = true; }
 }

 // A class representing your current hand of cards.
 public class Hand<T extends Card> {
     ArrayList<T> myCards = new ArrayList<T>();

    // Obtaining the score of your deck:
     public int score() {
         int score = 0;
         // Add up all your cards' values.
         for (T card: cards) {
             score += card.value();
         }
         return score;
     }

    // Adding a card to your deck:
     public void addCard(T card) {
         cards.add(card);
     }
 }
/**
 * Driver program that creates standard 52-card deck (as Card array)
 * and prints out each card in deck.
 *
 * @author Josh Clemens
 * @version ???
 */

public class Main {

	/* ALGORITHM
	*
	1. Generate 52 card deck into Card array
	- ???
	2. Print deck (simple)
	- ???
	*
	*/
    
	public static void main(String[] args) {

        
		/*** RUNNING TESTER ***/
		//uncomment line below to run CardTester:
		// CardTester.main(null);

		/*** DRIVER PROGRAM ***/
		//1. Generate 52 card deck into Card array

        Card[] cardObj = new Card[52];
        char[] suits = {Card.HEART, Card.DIAMOND, Card.SPADE, Card.CLUB};

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                cardObj[i * 13 + j] = new Card(j + 1, suits[i]);
            }
        }
        
        // for (int i = 0; i <= 12; i++){
        //     cardObj[i] = new Card(i + 1, '♥');
        //     System.out.print(cardObj[i].toString());

        // }
        // System.out.print("\n");
        // for (int i = 1; i <= 13; i++){
       
        //     cardObj[i+12] = new Card(i, '♦');
        //     System.out.print(cardObj[i+12].toString());
        // }
        // System.out.print("\n");
        // for (int i = 1; i <= 13; i++){
    
        //     cardObj[i+25] = new Card(i, '♣');
        //     System.out.print(cardObj[i+25].toString());
        // }
        // System.out.print("\n");
        // for (int i = 1; i <= 13; i++){

        //     cardObj[i+38] = new Card(i, '♠');
        //     System.out.print(cardObj[i+38].toString());
        // }
        // System.out.print("\n");
        
		//2. Print deck

        for(int i = 0; i < cardObj.length; i++){
            if(i % 13 == 0 && i != 0){
                System.out.println();
            }
            System.out.print(cardObj[i] + "\t");
        }
        System.out.println();


        //hacker challenge
        for(int i = 0; i < cardObj.length; i += 13){
            String[][] cardRow = new String[13][5];

            for(int card = 0; card < cardRow.length; card++){
                cardRow[card] = cardObj[i + card].getPrintCard().split("\n");
            }
            
            for(int j = 0; j < 5; j++){
                for(String[] card: cardRow){
                    System.out.print(card[j] + " ");
                }
                System.out.println();
            }
        }

        
        for (int i = 0; i < 52; i++){
           System.out.print(cardObj[i].getPrintCard());
            // System.out.print(cardObj[i].getSuit());
        }

        //testing lines
        // System.out.print(cardObj[0].getPrintCard());
        // System.out.print(cardObj[44].getPrintCard());
        // System.out.print(cardObj[9].getPrintCard());
        
        // System.out.println("more testing");
        // System.out.println(cardObj[0].toString());
        // System.out.println(cardObj[1].toString());
        // System.out.println(cardObj[2].toString());
        // System.out.println(cardObj[3].toString());
        // System.out.println(cardObj[4].toString());
        // System.out.println(cardObj[5].toString());
        // System.out.println(cardObj[6].toString());
        // System.out.println(cardObj[7].toString());
        // System.out.println(cardObj[8].toString());
        // System.out.println(cardObj[9].toString());
        // System.out.println(cardObj[10].toString());
        // System.out.println(cardObj[11].toString());
        // System.out.println(cardObj[12].toString());
        // System.out.println(cardObj[13].toString());
        // System.out.println(cardObj[14].toString());
        // System.out.println(cardObj[15].toString());
        // System.out.println(cardObj[16].toString());
        // System.out.println(cardObj[17].toString());
        // System.out.println(cardObj[18].toString());
        // System.out.println(cardObj[19].toString());
        // System.out.println(cardObj[20].toString());
        // System.out.println(cardObj[21].toString());
        // System.out.println(cardObj[22].toString());
        // System.out.println(cardObj[23].toString());
        // System.out.println(cardObj[24].toString());
        // System.out.println(cardObj[25].toString());
        // System.out.println(cardObj[26].toString());
        // System.out.println(cardObj[27].toString());
        // System.out.println(cardObj[28].toString());
        // System.out.println(cardObj[29].toString());
        // System.out.println(cardObj[30].toString());
        // System.out.println(cardObj[31].toString());
        // System.out.println(cardObj[32].toString());
        // System.out.println(cardObj[33].toString());
        // System.out.println(cardObj[34].toString());
        // System.out.println(cardObj[35].toString());
        // System.out.println(cardObj[36].toString());
        // System.out.println(cardObj[37].toString());
        // System.out.println(cardObj[38].toString());
        // System.out.println(cardObj[39].toString());
        // System.out.println(cardObj[40].toString());
        // System.out.println(cardObj[41].toString());
        // System.out.println(cardObj[42].toString());
        // System.out.println(cardObj[43].toString());
        // System.out.println(cardObj[44].toString());
        // System.out.println(cardObj[45].toString());
        // System.out.println(cardObj[46].toString());
        // System.out.println(cardObj[47].toString());
        // System.out.println(cardObj[48].toString());
        // System.out.println(cardObj[49].toString());
        // System.out.println(cardObj[50].toString());
        // System.out.println(cardObj[51].toString());

        
        
	}
}
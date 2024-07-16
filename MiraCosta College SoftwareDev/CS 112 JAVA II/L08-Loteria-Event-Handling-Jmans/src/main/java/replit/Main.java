package replit;

import com.google.errorprone.annotations.ForOverride;
//IMPORTED PACKAGES
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.image.ImageView;
import javafx.scene.control.Button;
import javafx.scene.control.ProgressBar;
import javafx.scene.text.TextAlignment;
import javafx.scene.text.Font;

import javafx.scene.layout.VBox;
import javafx.geometry.Pos;

import javafx.event.EventHandler;
import javafx.event.ActionEvent;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main extends Application{
	//CONSTANTS
    private static final LoteriaCard[] LOTERIA_CARDS = {
            new LoteriaCard("Las matematicas", "1.png", 1),
            new LoteriaCard("Las ciencias", "2.png", 2),
            new LoteriaCard("La Tecnología", "8.png", 8),
            new LoteriaCard("La ingeniería", "9.png", 9)
    };

	//CLASS-LEVEL VARIABLES
    private Label messageLabel, titleLabel;
    private ImageView cardImageView;
    private Button drawCardButton;
    private ProgressBar gameProgressBar;
    private int count = 0;
    private LoteriaCard[] shuffleCards;

	//GUI METHODS
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        //other setup stuff
        shuffleCards = new LoteriaCard[LOTERIA_CARDS.length];
        //shuffle cards here
        shuffleCards = LOTERIA_CARDS.clone();
        List<LoteriaCard> list = Arrays.asList(shuffleCards);
        Collections.shuffle(list);
        list.toArray(shuffleCards);
        System.out.println(Arrays.toString(shuffleCards));
        //end shuffle cards

        //instanciate components
        titleLabel = new Label("Welcome to EChALE STEM Loteria!");
        cardImageView = new ImageView();
        messageLabel = new Label("Click the button to randomly draw a card. The progress bar will indicate how far we're into the game.");
        drawCardButton = new Button("Draw Random Card");
        gameProgressBar = new ProgressBar(0.0);

        //SET COMPONENT PROPERTIES
        titleLabel.setFont(new Font(18.0));
        
        LoteriaCard tempCard = new LoteriaCard();
        cardImageView.setImage(tempCard.getImage());
        cardImageView.setFitWidth(300);
        cardImageView.setPreserveRatio(true);

        messageLabel.setWrapText(true);
        messageLabel.setTextAlignment(TextAlignment.CENTER);

        //ADD EVENT HANDLING
        drawCardButton.setOnAction( new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event){
                    if(count == shuffleCards.length){
                        //end game condition
                        System.out.println("END GAME");
                        gameProgressBar.setStyle("-fx-accent: red");
                        messageLabel.setText("GAME OVER");
                        drawCardButton.setDisable(true);
                        cardImageView.setImage(new LoteriaCard().getImage());
                    } else {
                        LoteriaCard drawnCard = shuffleCards[count];
                        count++;

                        cardImageView.setImage(drawnCard.getImage());
                        messageLabel.setText(drawnCard.getCardName());        

                        //update progress bar
                        double currentProgress = count / (double) shuffleCards.length;
                        gameProgressBar.setProgress(currentProgress);
                    }
                }
            }
        );
        
        // SET LAYOUT
        VBox mainLayout = new VBox();
        mainLayout.getChildren().addAll(titleLabel, cardImageView, messageLabel, drawCardButton, gameProgressBar); 

        mainLayout.setAlignment(Pos.CENTER);
        

        //SET SCENE AND SHOW
        Scene scene = new Scene(mainLayout, 350, 500);
        primaryStage.setScene(scene);
        primaryStage.setTitle("EChALE STEM Loteria");
        primaryStage.show();
    }
}

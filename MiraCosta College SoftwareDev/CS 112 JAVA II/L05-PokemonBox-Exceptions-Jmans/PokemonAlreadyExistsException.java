public class PokemonAlreadyExistsException extends Exception {
    Pokemon dupe;
    public PokemonAlreadyExistsException(){
        super("\nError! Pokemon already exists in box!");
    }
    
    public PokemonAlreadyExistsException(String message, Pokemon dupe){
        super(message + " Dupe Pokemon = " + dupe);
        this.dupe = dupe;
    }

    public Pokemon getDupe(){
        return this.dupe;
    }
}
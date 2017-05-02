package pratica;

/**
 *
 * @author matheus
 */

public class FullStackException extends RuntimeException {

    public FullStackException() {
        this("PILHA ESTA CHEIA");
    }

    public FullStackException(String exception) {
        super(exception);
    }
}

public class Piece
{
    public enum Type
    {
        King, Queen, Rook, Bishop, Knight, Pawn
    }

    public enum Color
    {
        White, Black
    }

    private Type pieceType;
    private Color color;

    public Piece(Type pt, Color c)
    {
        pieceType = pt;
        color = c;
    }

    public Type getPieceType()
    {
        return pieceType;
    }

    public void setPieceType(Type pieceType)
    {
        this.pieceType = pieceType;
    }

    public Color getColor()
    {
        return color;
    }

    public void setColor(Color color)
    {
        this.color = color;
    }
}

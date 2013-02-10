public class ChessBoard
{
    private Piece[][] board = new Piece[8][8];

    public class Position
    {
        private int x;
        private int y;

        public Position(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    public ChessBoard()
    {
        board[0][0] = new Piece(Piece.Type.Bishop, Piece.Color.Black);
        // 31 more
    }

    public Piece getPiece(Position position)
    {
        return board[position.x][position.y];
    }

    public void movePiece(Position from, Position to)
    {
    }
}

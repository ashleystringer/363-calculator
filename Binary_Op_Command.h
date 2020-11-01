class Binary_Op_Command : Expr_Command {
	public:
		bool execute(void);
		virtual int evaluate (int n1, int n2) const;
};

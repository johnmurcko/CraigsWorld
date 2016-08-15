class GridCell {
	private:
		static int kWidth;
		static int kHeight;
		float x;
		float y;
		GridCell * cell_right;
		GridCell * cell_left;
		GridCell * cell_up;
		GridCell * cell_down;
		std::vector<Entity*> cell_entity;
	public:
		GridCell(int x, int y, int width, int height);
		void setCellRight(GridCell * cell_right);
		void setCellLeft(GridCell * cell_left);
		void setCellUp(GridCell * cell_up);
		void setCellDown(GridCell * cell_down);
		void addEntity(Entity * entity);
		void removeEntity(Entity * entity);
		void update();
		void findCollisions();
};

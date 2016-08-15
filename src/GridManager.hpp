class GridManager {
	private:
		static const int kHorizontalCellCount = 50;
		static const int kVerticalCellCount = 50;
		GridCell *** cell;
		static GridManager * shared_grid_manager;
		static bool instance_exists;
	public:
		GridManager(int horiz_cell_count, int vert_cell_count);	
		static GridManager * getInstance();
		void updateGrids();
};

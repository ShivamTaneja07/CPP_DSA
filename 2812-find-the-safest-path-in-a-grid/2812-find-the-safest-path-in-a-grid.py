class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        adjacent_cells = [[1,0], [0,1], [-1,0], [0,-1]]

        #impossible cases
        if grid[0][0] == 1 or grid[-1][-1] == 1: 
            return 0

        #First use Breadth First Search(BFS) to calculate the smallest distance from thieves to each tile
        n = len(grid)
        queue = deque()
        
        #finding thieves
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.append([i, j])

        #BFS(0th roots are all thiefs' locations)
        while queue:
            #Marking the root as visited by removing from queue
            i, j = queue.popleft()
            value = grid[i][j]

            for delta_i, delta_j in adjacent_cells:
                x, y = i + delta_i, j + delta_j

                #last if clause means that we won't return to visited roots
                if min(x, y) >= 0 and max(x, y) < n and grid[x][y] == 0:
                    #Now the value equals the depth of BFS from the thief root
                    grid[x][y] = value + 1
                    #Adding next root to the queue
                    queue.append([x, y])
        

        #Secondly we use Greedy
        start_safeness = grid[0][0] - 1
        max_heap = [(-start_safeness, 0, 0)]
        
        #Graph of visited nodes
        visited = [[False] * n for i in range(n)]
        visited[0][0] = True
        
        while max_heap:
            #We get the root with the biggest ABSOLUTE value
            neg_safeness, i, j = heapq.heappop(max_heap)
            current_safeness = -neg_safeness
            
            #Result if we get to finish
            if i == n - 1 and j == n - 1:
                return current_safeness
            
            for delta_i, delta_j in adjacent_cells:
                x, y = i + delta_i, j + delta_j
                
                #If within edges
                if 0 <= x < n and 0 <= y < n and not visited[x][y]:
                    visited[x][y] = True
                    next_safeness = min(current_safeness, grid[x][y] - 1)
                    
                    #Push into the heap, the latest val
                    heapq.heappush(max_heap, (-next_safeness, x, y))
                    
        return 0

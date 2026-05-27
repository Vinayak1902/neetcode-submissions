class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = [[] for _ in range(n)]
        for u,v,cost in flights:
            adj[u].append([v,cost])
        INF = float("inf")
        dist = [[INF]*(k+4) for _ in range(n)]
        dist[src][0] = 0
        minHeap = [(0,src,-1)]
        while len(minHeap):
            cost, node, stops = heapq.heappop(minHeap)
            if node == dst:
                return cost
            if stops == k or dist[node][stops+1]<cost:
                continue
            for neighbor,cst in adj[node]:
                totalCst = cost + cst
                numStops = stops +1
                if dist[neighbor][numStops+1] > totalCst:
                    dist[neighbor][numStops+1] = totalCst
                    heapq.heappush(minHeap,(totalCst,neighbor,numStops))
        return -1

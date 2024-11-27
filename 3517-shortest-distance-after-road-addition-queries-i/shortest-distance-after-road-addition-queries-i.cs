
public class Solution
{
    
    public int FindMinDistance(List<List<int>> adjList, int n)
    {
        int[] dp = new int[n];
        dp[n - 1] = 0; 
              for (int currentNode = n - 2; currentNode >= 0; currentNode--)       {           int minDistance = n;                      foreach (int neighbor in adjList[currentNode])           {               minDistance = Math.Min(minDistance, dp[neighbor] + 1);           }           dp[currentNode] = minDistance;        }       return dp[0];   }
   public int[] ShortestDistanceAfterQueries(int n, int[][] queries)   {       List<int> answer = new List<int>();       List<List<int>> adjList = new List<List<int>>();
              for (int i = 0; i < n; i++)       {           adjList.Add(new List<int>());       }
              for (int i = 0; i < n - 1; i++)       {           adjList[i].Add(i + 1);       }
              foreach (int[] road in queries)       {           int u = road[0];           int v = road[1];           adjList[u].Add(v); 
                      answer.Add(FindMinDistance(adjList, n));       }
              return answer.ToArray();
    }
}
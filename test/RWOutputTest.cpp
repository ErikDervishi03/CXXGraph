#include "gtest/gtest.h"
#include "Graph.hpp"

inline bool exists_test(const std::string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

TEST(RWOutputTest, test_1)
{
    CXXGRAPH::Node<int> node1(1, 1);
    CXXGRAPH::Node<int> node2(2, 2);
    CXXGRAPH::Node<int> node3(3, 3);
    std::pair<const CXXGRAPH::Node<int> *, const CXXGRAPH::Node<int> *> pairNode(&node1, &node2);
    CXXGRAPH::DirectedWeightedEdge<int> edge1(1, pairNode, 1);
    CXXGRAPH::DirectedWeightedEdge<int> edge2(2, node2, node3, 1);
    CXXGRAPH::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);
    std::list<const CXXGRAPH::Edge<int> *> edgeSet;
    edgeSet.push_back(&edge1);
    edgeSet.push_back(&edge2);
    edgeSet.push_back(&edge3);
    CXXGRAPH::Graph<int> graph(edgeSet);
    int res = graph.writeToFile();
    ASSERT_EQ(res, 0);
    ASSERT_TRUE(exists_test("graph.csv"));
    ASSERT_FALSE(exists_test("graph_NodeFeat.csv"));
    ASSERT_FALSE(exists_test("graph_EdgeWeight.csv"));
}

TEST(RWOutputTest, test_2)
{
    CXXGRAPH::Node<int> node1(1, 1);
    CXXGRAPH::Node<int> node2(2, 2);
    CXXGRAPH::Node<int> node3(3, 3);
    std::pair<const CXXGRAPH::Node<int> *, const CXXGRAPH::Node<int> *> pairNode(&node1, &node2);
    CXXGRAPH::DirectedWeightedEdge<int> edge1(1, pairNode, 5);
    CXXGRAPH::DirectedWeightedEdge<int> edge2(2, node2, node3, 4);
    CXXGRAPH::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);
    std::list<const CXXGRAPH::Edge<int> *> edgeSet;
    edgeSet.push_back(&edge1);
    edgeSet.push_back(&edge2);
    edgeSet.push_back(&edge3);
    CXXGRAPH::Graph<int> graph(edgeSet);
    int res = graph.writeToFile(CXXGRAPH::Graph<int>::InputOutputFormat::STANDARD_CSV);
    ASSERT_EQ(res, 0);
    ASSERT_TRUE(exists_test("graph.csv"));
    ASSERT_FALSE(exists_test("graph_NodeFeat.csv"));
    ASSERT_FALSE(exists_test("graph_EdgeWeight.csv"));
}

TEST(RWOutputTest, test_3)
{
    CXXGRAPH::Node<int> node1(1, 1);
    CXXGRAPH::Node<int> node2(2, 2);
    CXXGRAPH::Node<int> node3(3, 3);
    std::pair<const CXXGRAPH::Node<int> *, const CXXGRAPH::Node<int> *> pairNode(&node1, &node2);
    CXXGRAPH::DirectedWeightedEdge<int> edge1(1, pairNode, 5);
    CXXGRAPH::DirectedEdge<int> edge2(2, node2, node3);
    CXXGRAPH::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);
    std::list<const CXXGRAPH::Edge<int> *> edgeSet;
    edgeSet.push_back(&edge1);
    edgeSet.push_back(&edge2);
    edgeSet.push_back(&edge3);
    CXXGRAPH::Graph<int> graph(edgeSet);
    int res = graph.writeToFile(CXXGRAPH::Graph<int>::InputOutputFormat::STANDARD_CSV, ".", "test_3");
    ASSERT_EQ(res, 0);
    ASSERT_TRUE(exists_test("test_3.csv"));
    ASSERT_FALSE(exists_test("test_3_NodeFeat.csv"));
    ASSERT_FALSE(exists_test("test_3_EdgeWeight.csv"));
}

TEST(RWOutputTest, test_4)
{
    CXXGRAPH::Node<int> node1(1, 1);
    CXXGRAPH::Node<int> node2(2, 2);
    CXXGRAPH::Node<int> node3(3, 3);
    CXXGRAPH::DirectedEdge<int> edge2(2, node2, node3);
    CXXGRAPH::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);
    std::list<const CXXGRAPH::Edge<int> *> edgeSet;
    edgeSet.push_back(&edge2);
    edgeSet.push_back(&edge3);
    CXXGRAPH::Graph<int> graph(edgeSet);
    int res = graph.writeToFile(CXXGRAPH::Graph<int>::InputOutputFormat::OUT_1, "test_4");
    ASSERT_EQ(res, -1);
    ASSERT_FALSE(exists_test("test_4.csv"));
    ASSERT_FALSE(exists_test("test_4_NodeFeat.csv"));
    ASSERT_FALSE(exists_test("test_4_EdgeWeight.csv"));
}

TEST(RWOutputTest, test_5)
{
    CXXGRAPH::Node<int> node1(1, 1);
    CXXGRAPH::Node<int> node2(2, 2);
    CXXGRAPH::Node<int> node3(3, 3);
    CXXGRAPH::DirectedEdge<int> edge2(2, node2, node3);
    CXXGRAPH::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);
    std::list<const CXXGRAPH::Edge<int> *> edgeSet;
    edgeSet.push_back(&edge2);
    edgeSet.push_back(&edge3);
    CXXGRAPH::Graph<int> graph(edgeSet);
    int res = graph.writeToFile(CXXGRAPH::Graph<int>::InputOutputFormat::STANDARD_CSV, ".", "test_5", false, true, true);
    ASSERT_EQ(res, 0);
    ASSERT_TRUE(exists_test("test_5.csv"));
    ASSERT_TRUE(exists_test("test_5_NodeFeat.csv"));
    ASSERT_TRUE(exists_test("test_5_EdgeWeight.csv"));
}

TEST(RWOutputTest, test_6)
{
    CXXGRAPH::Node<int> node1(1, 1);
    CXXGRAPH::Node<int> node2(2, 2);
    CXXGRAPH::Node<int> node3(3, 3);
    CXXGRAPH::DirectedWeightedEdge<int> edge2(2, node2, node3, 1);
    CXXGRAPH::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);
    std::list<const CXXGRAPH::Edge<int> *> edgeSet;
    edgeSet.push_back(&edge2);
    edgeSet.push_back(&edge3);
    CXXGRAPH::Graph<int> graph(edgeSet);
    int res = graph.writeToFile(CXXGRAPH::Graph<int>::InputOutputFormat::STANDARD_CSV, ".", "test_6", false, false, true);
    ASSERT_EQ(res, 0);
    ASSERT_TRUE(exists_test("test_6.csv"));
    ASSERT_FALSE(exists_test("test_6_NodeFeat.csv"));
    ASSERT_TRUE(exists_test("test_6_EdgeWeight.csv"));
}

TEST(RWOutputTest, test_7)
{
    CXXGRAPH::Node<int> node1(1, 1);
    CXXGRAPH::Node<int> node2(2, 2);
    CXXGRAPH::Node<int> node3(3, 3);
    CXXGRAPH::DirectedWeightedEdge<int> edge2(2, node2, node3, 1);
    CXXGRAPH::UndirectedWeightedEdge<int> edge3(3, node1, node3, 6);
    std::list<const CXXGRAPH::Edge<int> *> edgeSet;
    edgeSet.push_back(&edge2);
    edgeSet.push_back(&edge3);
    CXXGRAPH::Graph<int> graph(edgeSet);
    int res = graph.writeToFile(CXXGRAPH::Graph<int>::InputOutputFormat::STANDARD_CSV, ".", "test_7", false, true, false);
    ASSERT_EQ(res, 0);
    ASSERT_TRUE(exists_test("test_7.csv"));
    ASSERT_TRUE(exists_test("test_7_NodeFeat.csv"));
    ASSERT_FALSE(exists_test("test_7_EdgeWeight.csv"));
}
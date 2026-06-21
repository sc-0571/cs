



使用 AWS 官方 Labs 的 MCP 服务器（Python）
这是 AWS 官方 Labs 提供的 Python 实现，功能更丰富，支持重排序（Reranking）和元数据过滤等高级特性。

支持通过元数据对检索结果进行过滤，并可启用 Amazon 或 Cohere 的重排序模型来提升检索结果的精准度。

json
{
  "mcpServers": {
    "awslabs.bedrock-kb-retrieval-mcp-server": {
      "command": "uvx",
      "args": ["awslabs.bedrock-kb-retrieval-mcp-server@latest"],
      "env": {
        "AWS_PROFILE": "your-profile-name",
        "AWS_REGION": "us-east-1"
      }
    }
  }
}


使用 AWS 托管服务 Bedrock AgentCore Gateway（生产级）
如果你的需求是在生产环境中将知识库暴露为远程、可统一认证的 MCP 服务，AgentCore Gateway 是官方推荐的托管方案。它可以将你的知识库或 Lambda 函数封装成一个标准的 MCP 端点。

核心优势：由 AWS 托管，集成了 Amazon Cognito 认证（支持 OAuth 2.0 的 client_credentials 流程），适合团队共享和企业级部署。

架构模式：AgentCore Gateway 接收 MCP 协议请求，转换为对后端 AWS Lambda 函数的调用，再由 Lambda 函数去调用 Bedrock Knowledge Base 的 Retrieve API。


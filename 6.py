from pyspark.sql import SparkSession
from pyspark.sql.functions import split, explode, col, lower

# Initialize Spark Session
spark = SparkSession.builder \
    .appName("RealTimeHashtagAnalysis") \
    .getOrCreate()

# 1. Setup Streaming Source (Monitoring a directory for new JSON files)
# As per methodology in 1000266138.jpg, we monitor an input directory
file_schema = "user string, text string, timestamp timestamp"

# Replace 'input_data' with your actual folder path
tweet_stream = spark.readStream \
    .schema(file_schema) \
    .json("input_data/") 

# 2. Extract Hashtags (The 'Cleaning' and 'Extraction' step)
# Split text by spaces, explode into rows, and filter for '#'
words = tweet_stream.select(
    explode(split(col("text"), " ")).alias("word")
)

hashtags = words.filter(col("word").startswith("#")) \
    .select(lower(col("word")).alias("hashtag"))

# 3. Aggregate Counts
hashtag_counts = hashtags.groupBy("hashtag").count()

# 4. Output to Console (Sink)
query = hashtag_counts.writeStream \
    .outputMode("complete") \
    .format("console") \
    .start()

query.awaitTermination()
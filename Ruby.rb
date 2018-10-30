class WordCounter
    def initialize(file_name)
        @file = File.new(file_name).read()	
	end

	def count
		@str = @file.force_encoding("UTF-8")
        @str.lstrip!
        @str = @str.split(/[\W|\s][\W*|\s*]*/)
		puts @str.length
	end

	def uniq_count
        puts @str.uniq.length
	end

	def frequency
        $i = 0
        $j = 0 
        $num = @str.length();
        wordNum = Hash.new();
        while $i < $num  do
            word = @str[$i];
            if(wordNum.has_key?(word))
                wordNum[word] = wordNum[word] + 1;
            else
                wordNum[word] = 1;
            end
            $i += 1
        end
        while $j < wordNum.length do
            puts wordNum.keys[$j] + ": #{wordNum[wordNum.keys[$j]]}"
            $j += 1
        end
    end
end

file1 = WordCounter.new(ARGV.first)
file1.count
file1.uniq_count
file1.frequency

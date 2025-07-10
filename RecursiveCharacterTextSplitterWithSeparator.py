class RecursiveCharacterTextSplitterWithSeparator(RecursiveCharacterTextSplitter):

	# Start recursive splitting
	def _split(text: str, separators: List[str]) -> List[Tuple[str, str]]:
		if not separators:
			return [(text, '')]

		sep = separators[0]
		rest = separators[1:]

		# Split using current separator
		splits = text.split(sep) if sep else list(text)

		good_splits = []
		current_chunk = ""
		for i, piece in enumerate(splits):
			next_piece = (sep if current_chunk else "") + piece
			if len(current_chunk) + len(next_piece) <= self.chunk_size:
				current_chunk += next_piece
			else:
				if current_chunk:
					good_splits.append((current_chunk, sep))
				current_chunk = piece

		if current_chunk:
			good_splits.append((current_chunk, sep))

		# If everything fits in chunks, return
		if all(len(chunk) <= self.chunk_size for chunk, _ in good_splits):
			return good_splits
		else:
			# Try next separator
			further_split = []
			for chunk, _ in good_splits:
				if len(chunk) <= self.chunk_size:
					further_split.append((chunk, sep))
				else:
					further_split.extend(_split(chunk, rest))
			return further_split

    def split_text(self, text: str) -> List[Tuple[str, str]]:
        """
        Returns a list of tuples. Each tuple contains:
        - the text chunk
        - the separator used to split the chunk
        """
        final_chunks_with_sep = []



        final_chunks_with_sep = _split(text, self.separators)
        return final_chunks_with_sep
